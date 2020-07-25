//
//  main.cpp
//  309-最佳买卖股票时机含冷冻期
//
//  Created by 董深育 on 2020/7/25.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=(int)prices.size();
        if(len==0){
            return 0;
        }
        vector<vector<int>>dp(len,vector<int>(3));
        //在第0天 拥有了股票，买入股票
        dp[0][0]=-prices[0];
        //不持有股票 处在冷静期
        dp[0][1]=0;
        //不持有股票 没有处在冷静期
        dp[0][2]=0;
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        return max(dp[len-1][1],dp[len-1][2]);
        

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
