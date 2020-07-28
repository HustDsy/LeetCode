//
//  main.cpp
//  139-单词拆分
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=(int)s.length();
        bool dp[len+1];
        dp[0]=true;
        for(int i=1;i<=len;i++){
            dp[i]=false;
            for(int j=0;j<i;j++){
                string temp=s.substr(j,i-j);
                bool ret=find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end();
                if(dp[j]&&ret){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main(int argc, const char * argv[]) {
    string s = "catsandog";
    vector<string>wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution ss;
    ss.wordBreak(s, wordDict);
    return 0;
}

