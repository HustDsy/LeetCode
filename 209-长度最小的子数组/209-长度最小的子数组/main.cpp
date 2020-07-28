//
//  main.cpp
//  209-长度最小的子数组
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //暴力法,果断超时
    int sum(int begin,int len,vector<int>& nums){
        int ret=0;
        for(int i=begin;i<begin+len;i++){
            ret+=nums[i];
        }
        return ret;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz=(int)nums.size();
        if(sz==0){
            return 0;
        }
        for(int len=1;len<=sz;len++){
            for(int i=0;i<sz-len+1;i++){
                int ret=sum(i,len,nums);
                if(ret>=s){
                    return len;
                }
            }
        }
        return 0;
    }
    //前缀和+二分查找
    //二分查找，找到右边第一个比目标值要大的
    //这里主要是优化第二层循环的查找部分
    //将for循环查找变为二分查找，用空间换时间
    int getIndex(int l,int r,vector<int>nums,int target){
        while(l<r){
            int mid=l+((r-l)>>1);
            if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[l]>=target?l:-1;
        
    }
    int minSubArrayLen_BinarySearch(int s, vector<int>& nums) {
        int len=(int)nums.size();
        if(len==0){
            return 0;
        }
        vector<int>sums(len+1,0);
        sums[0]=0;
        for(int i=1;i<len+1;i++){
            sums[i]=sums[i-1]+nums[i-1];
        }
        int minLen=INT_MAX;
        for(int i=1;i<len+1;i++){
           // int target=s+sums[i]-nums[i];
            int target=s+sums[i-1];
            int index=getIndex(i, len, sums,target);
            int ret;
            if(index==-1){
                ret=0;
            }else{
        //此时的最小长度
            ret=index-i+1;
            minLen=min(ret,minLen);
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
    //双指针
    int minSubArrayLen_DoublePoint(int s, vector<int>& nums) {
        int len=(int)nums.size();
        if(len==0){
            return 0;
        }
        int i=0;
        int j=0;
        int minLen=INT_MAX;
        int sum=0;
        while(j<len){
            sum+=nums[j];
            while(sum>=s){
                minLen=min(minLen,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minLen==INT_MAX?0:minLen;
        
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>num={2,3,1,2,4,3};
    int len=s.minSubArrayLen_BinarySearch(7, num);
    cout<<len;
    return 0;
}
