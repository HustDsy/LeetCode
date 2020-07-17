//
//  main.cpp
//  81-搜索旋转排序数组 II
//
//  Created by 董深育 on 2020/7/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin=0;
        int end=(int)nums.size()-1;
        if (!(end+1)) return false;
        if (end == 0) return nums[0] == target ? true : false;
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            //开始分成两个区间，（begin，mid）和(mid+1,end),看哪一段有序
            if(nums[mid]==target){
                return true;
            }
            //消除重复元素的影响
            if(nums[mid]==nums[begin]){
                begin++;
            }
             //如果左侧有序,[begin.mid-1]
            if(nums[mid]>nums[begin]){
                //在这一段的话，那么就end往这一段靠
                if(nums[begin]<=target&&target<nums[mid]){
                    end=mid-1;
                }else{
                    //不再这一段，begin调到下一段的开头
                    begin=mid+1;
                }
            }else if(nums[mid]<nums[begin]){
                if (nums[mid] <target && target <= nums[end]) {
                    //在这一段的话，begin往这一段靠
                    begin= mid + 1;
                } else {
                    //不再这一段，去另一段找
                    end = mid - 1;
                }

            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>nums={1,1,1,3,1};
    int ret=s.search(nums, 3);
    return 0;
}
