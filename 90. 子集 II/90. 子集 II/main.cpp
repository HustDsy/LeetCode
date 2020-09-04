//
//  main.cpp
//  90. 子集 II
//
//  Created by 董深育 on 2020/9/4.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    void dfs(int len,int begin,vector<int>& nums){
        if(len==temp.size()){
            ret.emplace_back(temp);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            //遇到重复的跳过
            if(i>begin&&nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            dfs(len,i+1,nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len=static_cast<int>(nums.size());
        if(len==0){
            return {};
        }
        ret.emplace_back(vector<int>{});
        sort(nums.begin(),nums.end());
        for(int k=1;k<=len;k++){
            dfs(k,0,nums);
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={1,2,2};
    vector<vector<int>>ret=s.subsetsWithDup(nums);
    return 0;
}
