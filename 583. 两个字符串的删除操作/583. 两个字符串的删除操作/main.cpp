//
//  main.cpp
//  583. 两个字符串的删除操作
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=(int)word1.length();
        int m=(int)word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n+m-2*dp[n][m];
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    s.minDistance("a", "b");
    return 0;
}
