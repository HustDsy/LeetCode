//
//  main.cpp
//  632-最小区间
//
//  Created by 董深育 on 2020/8/1.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using  namespace std;

class Solution {
public:
    
    //将数组排序 返回flag
    vector<vector<int>>sort(vector<int>nums1,vector<int>flag1,vector<int>nums2,vector<int>flag2){
        int len1=(int)nums1.size();
        int len2=(int)nums2.size();
        vector<vector<int>>ret;
        vector<int>ret_nums(len1+len2,0);
        vector<int>ret_flag(len1+len2,0);
        int begin1=0;
        int begin2=0;
        int k=0;
        while(begin1<len1&&begin2<len2){
            if(nums1[begin1]>nums2[begin2]){
                ret_nums[k]=nums2[begin2];
                ret_flag[k]=flag2[begin2];
                k++;
                begin2++;
            }else{
                ret_nums[k]=nums1[begin1];
                ret_flag[k]=flag1[begin1];
                k++;
                begin1++;
            }
          
        }
        while(begin1<len1){
            ret_nums[k]=nums1[begin1];
            ret_flag[k]=flag1[begin1];
            k++;
            begin1++;
        }
        while(begin2<len2){
            ret_nums[k]=nums2[begin2];
            ret_flag[k]=flag2[begin2];
            begin2++;
            k++;
        }
        ret.push_back(ret_nums);
        ret.push_back(ret_flag);
        return ret;
    }
    //判断一个数组 同时含有1-k个数
    bool isTrue(vector<int>flags,int k,int begin,int end){
        bool flag=true;
        int nums[k];
        for(int i=begin;i<=end;i++){
            nums[flags[i]]=1;
        }
        for(int i=0;i<k;i++){
            if(nums[i]!=1){
                return false;
            }
        }
        return flag;
        
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //初始化flag
        vector<vector<int>>flags=nums;
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {nums[0][0],nums[0][0]};
        }
        for(int i=0;i<nums.size();i++){
            //去重
            nums[i].erase(unique(nums[i].begin(), nums[i].end()), nums[i].end());
            for(int j=0;j<nums[i].size();j++){
                flags[i][j]=i;
            }
        }
        //开始全部排序
        vector<vector<int>>getRet;
        getRet.push_back(nums[0]);
        getRet.push_back(flags[0]);
        for(int i=1;i<nums.size();i++){
            getRet=sort(getRet[0], getRet[1], nums[i], flags[i]);
        }
        //容易知道最多有k个数的区间即可 保证每个数都在里面了
        int begin=0;
        int end=INT_MAX;
        int i=0;
        int j=0;
        int maxLen=(int)getRet[0].size();
        while(j<maxLen){
            if(j<maxLen&&isTrue(getRet[1], (int)nums.size(), i, j))
            {
                int begin1=getRet[0][i];
                int end1=getRet[0][j];
                if(end-begin>end1-begin1){
                    begin=begin1;
                    end=end1;
                }
                if(end-begin==end1-begin1&&begin>begin1){
                    begin=begin1;
                    end=end1;
                }
                i++;
                continue;
            }
            j++;
        }
        return {begin,end};
        /*
        for(int i=0;i<getRet[0].size();i++){
            //这里有重复元素，每个出现三遍的话，
            for(int len=i;len<getRet[0].size();len++){
                //如果这个长度包含所有的k
                if(isTrue(getRet[1], (int)nums.size(), i, len)){
                    int begin1=getRet[0][i];
                    int end1=getRet[0][len];
                    if(end-begin>end1-begin1){
                        begin=begin1;
                        end=end1;
                    }
                    if(end-begin==end1-begin1&&begin>begin1){
                        begin=begin1;
                        end=end1;
                    }
                }
            }
        }
         */
       // return {begin,end};
    }
     
    
    //哈希表+双指针
    vector<int> smallestRange_Hash(vector<vector<int>>& nums) {
        //得到有几个数组
        int n = (int)nums.size();
        //哈希表
        /*  如果列表集合为：
         0: [-1, 2, 3]
         1: [1]
         2: [1, 2]
         3: [1, 1, 3]
         那么可以得到这样一个哈希映射
         -1: [0]
         1: [1, 2, 3, 3]
         2: [0, 2]
         3: [0, 3]
         */
        unordered_map<int, vector<int>> indices;
        //记录数组的最大值和最小值
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (const int& x: nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }
        //记录这个数字在那几个列表chuxianguo1
        vector<int> freq(n);
        //记录当前区间包含了几个数字
        int inside = 0;
        //坐标指针在最小值，righ也在
        int left = xMin, right = xMin - 1;
        //最开始的区间全部覆盖了
        int bestLeft = xMin, bestRight = xMax;
        //当right<xMax的时候 开始查找
        while (right < xMax) {
            //right++ 相当与从第一个数字查找，如果不包括的话，right++扩大区间
            ++right;
            //判断right这个数字出现过几次，判断map包不包含这个数字
            if (indices.count(right)) {
                //包含的话，计算这个数字在哪几个列表里
                for (const int& x: indices[right]) {
                    //对应的freq[x]++,代表这个数字出现在这个nums[x]数组中
                    ++freq[x];
                    //如果这个x为一的话，那么就加一，主要是为了防止出现重复元素
                    if (freq[x] == 1) {
                        ++inside;
                    }
                }
                //如果已经包含了所有层次的话
                while (inside == n) {
                    //判断当前的区间和以前的区间的好坏
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    //开始缩小区间，判断所有包含坐标数字坐标的值
                    if (indices.count(left)) {
                        for (const int& x: indices[left]) {
                            --freq[x];
                            if (freq[x] == 0) {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }

        return {bestLeft, bestRight};
    }

};

int main(int argc, const char * argv[]) {
    vector<vector<int>>ret={{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}}
;
    Solution s;
    s.smallestRange(ret);
    std::cout << "Hello, World!\n";
    return 0;
}
