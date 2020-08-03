//
//  main.cpp
//  740-删除与获得点数
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()|| nums.size() == 0) {
            return 0;
        } else if (nums.size()== 1) {
            return nums[0];
        }
        int num=*max_element(nums.begin(), nums.end());
        vector<int>count(num+1,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int dp[num+1];
        dp[1]=count[1];
        dp[0]=0;
        for(int i=2;i<=num;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*count[i]);
        }
        return dp[num];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
