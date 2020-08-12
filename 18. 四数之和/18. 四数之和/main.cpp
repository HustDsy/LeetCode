//
//  main.cpp
//  18. 四数之和
//
//  Created by 董深育 on 2020/8/12.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ret;
        int len=(int)nums.size();
        if(len<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(nums[i]>target&&nums[i]>=0){
                return ret;
            }else if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int targetNum=target-nums[i];
            for(int j=i+1;j<len;j++){
                if(nums[j]>targetNum&&nums[j]>=0){
                    break;
                }else if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int l=j+1;
                int r=len-1;
                while(l<r){
                    if(nums[l]+nums[r]+nums[j]==targetNum){
                        vector<int>dd;
                        dd.push_back(nums[i]);
                        dd.push_back(nums[j]);
                        dd.push_back(nums[l]);
                        dd.push_back(nums[r]);
            
                        ret.push_back(dd);
                        while(l<r&&nums[l+1]==nums[l]){
                            l=l+1;
                        }
                        l=l+1;
                        while(l<r&&nums[r-1]==nums[r]){
                            r=r-1;
                        }
                        r=r-1;
                    }else if(nums[j]+nums[l]+nums[r]>targetNum){
                        r--;
                    }else if(nums[j]+nums[l]+nums[r]<targetNum){
                        l++;
                    }
                }
            }
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={1,-2,-5,-4,-3,3,3,5};
    s.fourSum(nums, -11);
    return 0;
}
