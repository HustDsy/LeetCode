//
//  main.cpp
//  44-通配符匹配
//
//  Created by 董深育 on 2020/7/27.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        //s的长度
        int m=s.length();
        //p的长度
        int n=p.length();
        //dp[i][j]表示s[i]和p[j]之前的字符串是否匹配
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[0][j]=true;
            }else{
                break;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }else{
                    dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    Solution ss;
    string s="aa";
    string p="a";
    bool ret=ss.isMatch(s, p);
    return 0;
}
