//
//  main.cpp
//  剑指 Offer 42-连续子数组的最大和
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int ret=INT_MIN;
        int len=(int)nums.size();
        int dp[len];
        dp[0]=nums[0];
        ret=max(ret,dp[0]);
        for(int i=1;i<len;i++){
            dp[i]=dp[i-1]>0?dp[i-1]+nums[i]:nums[i];
            ret=max(dp[i],ret);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
