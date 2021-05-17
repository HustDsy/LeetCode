//
//  main.cpp
//  1269. 停在原地的方案数
//
//  Created by dsy on 2021/5/13.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
  
    const int mod=1e9+7;

    int numWays(int steps, int arrLen) {
        //dp[i][k]=dp[i-1][k]+dp[i-1][k-1]+dp[i][k+1]
        //走i步 到达索引为k的方案
        arrLen=min(steps,arrLen);
        vector<vector<int>>dp(steps,vector<int>(arrLen,0));
        dp[0][0]=dp[0][1]=1;
        for(int i=1;i<steps;i++){
            for(int k=0;k<arrLen;k++){
                dp[i][k]=dp[i-1][k];
                if(k>=1){
                    dp[i][k]=(dp[i][k]+dp[i-1][k-1])%mod;
                }
                if(k<arrLen-1){
                     dp[i][k]=(dp[i][k]+dp[i-1][k+1])%mod;
                }
            }
        }
        return dp[steps-1][0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
