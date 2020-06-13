//
//  main.cpp
//  15-三数之和
//
//  Created by 董深育 on 2020/6/11.
//  Copyright © 2020 董深育. All rights reserved.
//
//超出时间限制
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()<3){
            return {};
        }else{
            //对nums数组进行排序
            sort(nums.begin(),nums.end());
            //用来记录满足条件的三元组
            for(int i=0;i<nums.size();i++){
                if(i==0||nums[i]!=nums[i-1]){
                    for(int j=i+1;j<nums.size();j++){
                        if(j==i+1||nums[j]!=nums[j-1]){
                            for(int r=j+1;r<nums.size();r++){
                                if(r==j+1||nums[r]!=nums[r-1]){
                                    if(nums[i]+nums[j]+nums[r]==0){
                                        vector<int>temp;
                                        temp.push_back(nums[i]);
                                        temp.push_back(nums[j]);
                                        temp.push_back(nums[r]);
                                        result.push_back(temp);
                                    }
                                }
                            }
                        }
                    }
                }
                
                
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution ss;
    vector<int>test={-1,0,1,2,-1,-4};
    vector<vector<int>>result=ss.threeSum(test);
    return 0;
}
