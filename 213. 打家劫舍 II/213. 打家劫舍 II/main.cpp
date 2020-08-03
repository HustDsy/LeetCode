//
//  main.cpp
//  213. 打家劫舍 II
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using  namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0){
            return 0;
        }else if(len==1){
            return nums[0];
        }else if(len==2){
            return max(nums[0],nums[1]);
        }
        //当最后一个不拿的话
        int dp1[len-1];
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        for(int i=2;i<len-1;i++){
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        //当拿最后一个的话 那么第一个就不能拿
        int dp2[len-1];
        dp2[0]=nums[1];
        dp2[1]=max(nums[1],nums[2]);
        for(int i=2;i<len-1;i++){
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i+1]);
        }
        int ret=max(dp2[len-2],dp1[len-2]);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
