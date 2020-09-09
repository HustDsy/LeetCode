//
//  main.cpp
//  16. 最接近的三数之和
//
//  Created by 董深育 on 2020/9/8.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=static_cast<int>(nums.size());
        if(len==0){
            return {};
        }
        sort(nums.begin(),nums.end());
        int pre=INT_MAX;
        int ret=INT_MAX;
        for(int i=0;i<len;i++){
            if(nums[i]==pre){
                continue;
            }
            pre=nums[i];
            int j=i+1;
            int k=len-1;
            int t=target-nums[i];
         
            while(j<k){
                int gap=t-nums[j]-nums[k];
                if(gap<0){
                    ret=abs(ret-target)<abs(target-(nums[j]+nums[i]+nums[k]))?ret:nums[j]+nums[i]+nums[k];
                    k--;
                }else if(gap>0){
                    ret=abs(ret-target)<abs(target-(nums[j]+nums[i]+nums[k]))?ret:nums[j]+nums[i]+nums[k];
                    j++;
                }else{
                    return target;
                }
            }
        }
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>nums={1,1,-1};
    s.threeSumClosest(nums, 2);
    return 0;
}
