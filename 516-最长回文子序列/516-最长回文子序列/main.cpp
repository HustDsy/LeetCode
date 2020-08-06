//
//  main.cpp
//  516-最长回文子序列
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=(int)s.size();
        vector<vector<int>>dp(len,vector<int>(len,0));
        for(int i=len-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
