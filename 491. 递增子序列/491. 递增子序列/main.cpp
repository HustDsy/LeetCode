//
//  main.cpp
//  491. 递增子序列
//
//  Created by 董深育 on 2020/8/25.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    //len要求的字符串长度 kk为已经满足的长度 begin 开始的字符串位置,n为nums的长度
    //判断是否包含nums[i]
    bool isVaild(int cur,vector<int>nums,int begin){
        for(int i=begin;i<=cur-1;i++){
            if(nums[cur]==nums[i]){
                return false;
            }
        }
        return true;
    }
    
    
    void dfs(int len,int kk,int begin,vector<int>nums,int n){
        if(len==kk){
            ret.push_back(temp);
            return;
        }
        for(int i=begin;i<n;i++){
            if(i>begin&&!isVaild(i, nums, begin)){
                          continue;
                      }
            if(!temp.empty()&&temp.back()>nums[i]){
                continue;
            }
            temp.emplace_back(nums[i]);
            dfs(len,kk+1,i+1,nums,n);
            temp.pop_back();
        }
    }
    //begin是上一次访问的位置 begin是这一次
    void otherDfs(int begin,int cur,vector<int>nums){
        if(cur==nums.size()){
            return;
        }
        //数组为空 ，或者cur==begin 或者大于的时候
        int kk=0;
        if(temp.empty()){
            kk=-INT_MAX;
        }else{
              kk=temp.back();
        }
        if((cur==begin&&(kk<=nums[cur]))||(cur>begin&&isVaild(cur,nums,begin)&&kk<=nums[cur])){
            temp.push_back(nums[cur]);
            if(temp.size()>=2){
                ret.push_back(temp);
            }
            otherDfs(cur+1,cur+1,nums);
            temp.pop_back();
        }
        otherDfs(begin,cur+1,nums);
    }
     
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=static_cast<int>(nums.size());
        if(n==0||n==1){
            return {};
        }
//        for(int len=2;len<=n;len++){
//            dfs(len,0,0,nums,n);
//        }
        otherDfs(0, 0, nums);
        return ret;
        

    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={
        1, 2, 3, 1,1};
    s.findSubsequences(nums);
    return 0;
}
