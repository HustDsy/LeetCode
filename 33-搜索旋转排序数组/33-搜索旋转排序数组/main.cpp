//
//  main.cpp
//  33-搜索旋转排序数组
//
//  Created by 董深育 on 2020/7/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin=0;
        int end=(int)nums.size()-1;
        if (!(end+1)) return -1;
        if (end == 0) return nums[0] == target ? 0 : -1;
        while(begin<=end){
            int mid=begin+(end-begin)/2;
            //开始分成两个区间，（begin，mid）和(mid+1,end),看哪一段有序
            if(nums[mid]==target){
                return mid;
            }
            //如果左侧有序,[begin.mid-1]
            if(nums[mid-1]>=nums[begin]){
                if(nums[begin]<=target&&target<nums[mid]){
                    end=mid-1;
                }else{
                    begin=mid+1;
                }
            }else{
                if (nums[mid] <target && target <= nums[end]) {
                    begin= mid + 1;
                } else {
                    end = mid - 1;
                }

            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>aaa={1,3};
    int ret=s.search(aaa, 0);
    return 0;
}
