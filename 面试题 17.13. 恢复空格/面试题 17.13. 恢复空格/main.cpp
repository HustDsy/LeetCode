//
//  main.cpp
//  面试题 17.13. 恢复空格
//
//  Created by 董深育 on 2020/7/24.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//单纯的动态规划 超时
/*
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int len=(int)sentence.length();
        int dp[len+1];
        dp[0]=0;
        for(int i=1;i<len+1;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<i;j++){
                if(find(dictionary.begin(), dictionary.end(), sentence.substr(j,i-j))!=dictionary.end()){
                    dp[i]=min(dp[i],dp[j]);
                    
                }
            }
        }
        return dp[len];
    }
};
 */
//字典树+动态规划
class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd;
    
    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie* curPos = this;

        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f;

        Trie* root = new Trie();
        for (auto& word: dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
