//
//  main.cpp
//  746. 使用最小花费爬楼梯
//
//  Created by dsy on 2020/12/21.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=(int)cost.size();
        vector<int>dp(len,INT_MAX);
        //爬到该楼层的最小花费
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<len;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[len-1],dp[len-2]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
