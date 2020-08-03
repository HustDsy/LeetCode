//
//  main.cpp
//  198-打家劫舍
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0){
            return 0;
        }else if(len==1){
            return nums[0];
        }
        int dp[len];
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<len;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[len-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
