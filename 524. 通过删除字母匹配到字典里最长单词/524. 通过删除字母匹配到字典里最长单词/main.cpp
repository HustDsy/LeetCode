//
//  main.cpp
//  524. 通过删除字母匹配到字典里最长单词
//
//  Created by dsy on 2021/3/24.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),[](string&a,string&b)->bool{
            return a.length()>b.length()||(a.length()==b.length()&&(a<b));
        });
        int dp[26];
        int ep[26];
        memset(dp,-1,sizeof(dp));
        memset(ep,-1,sizeof(dp));
        int sl=s.length();
        for(int i=0;i<sl;i++){
            dp[s[i]-'a']=dp[s[i]-'a']==-1?i:dp[s[i]-'a'];
            ep[s[i]-'a']=i;//最后出现的位置
        }
        for(string&t:dictionary){
            int len=t.size();
            if(len==0) return t;
            int left=dp[t[0]-'a'];
            if(left==-1) continue;
            int right=ep[t[len-1]-'a'];
            if(right==-1) continue;
            int i=1;
            left+=1;
            while(i<len&left<sl){
                if(t[i]==s[left]){
                    i++;
                }
                left++;
            }
            if(i==len) return t;
        }
        return "";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
