//
//  main.cpp
//  35-搜索插入位置
//
//  Created by 董深育 on 2020/7/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //这里注意return 不是strat+1而失start 比如【1 3 5 6】里查找2 ，最后一次start为0 end为0
    //还是会去循环里判断一次 之后start执行了mid+1,刚刚好+1了
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=(int)nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start=mid+1;;
            }else if(nums[mid]>target){
                end=mid-1;
            }
        }
        return start;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
