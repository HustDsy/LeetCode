//
//  main.cpp
//  375. 猜数字大小 II
//
//  Created by 董深育 on 2020/9/1.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int getMoneyAmount(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][i]=0;
        }
        for(int i=n;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                //对于i,j中间的数
                for(int k=i+1;k<=j-1;k++){
                    dp[i][j]=min(k+max(dp[i][k-1],dp[k+1][j]),dp[i][j]);
                }
                //对于i
                dp[i][j]=min(dp[i][j],i+dp[i+1][j]);
                //对于j
                dp[i][j]=min(dp[i][j],j+dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.getMoneyAmount(5);
    return 0;
}
