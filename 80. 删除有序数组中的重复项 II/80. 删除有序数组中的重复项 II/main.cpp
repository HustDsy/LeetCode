//
//  main.swift
//  80. 删除有序数组中的重复项 II
//
//  Created by dsy on 2021/4/6.
//
#include<iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        for(int i=0;i<nums.size();i++){
            if(slow<2||nums[i]!=nums[slow-2]){
                nums[slow]=nums[i];
                slow++;
            }
        }
        return slow;
    }
};
