//
//  main.cpp
//  714. 买卖股票的最佳时机含手续费
//
//  Created by dsy on 2020/12/17.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=static_cast<int>(prices.size());
        vector<vector<int>>dp(len,vector<int>(2,0));
        dp[0][0]=
        //当天交易完手里有股票
        dp[0][1]=-prices[0];
        //当天交易完手里没有股票
        dp[0][0]=0;
        for(int i=1;i<len;i++){
            //交易完没有股票
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            //交易完手里有股票
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[len-1][0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
