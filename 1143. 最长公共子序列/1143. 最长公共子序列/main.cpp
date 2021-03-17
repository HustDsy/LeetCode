//
//  main.cpp
//  1143. 最长公共子序列
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.longestCommonSubsequence("ezupkr", "ubmrapg");
    return 0;
}
