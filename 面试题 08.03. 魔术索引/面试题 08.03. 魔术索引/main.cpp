//
//  main.cpp
//  面试题 08.03. 魔术索引
//
//  Created by 董深育 on 2020/7/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //直接遍历
    int findMagicIndex(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i){
                return i;
            }else{
                i=max(i+1,nums[i]);
            }
        }
        return -1;
    }
    //二分查找
    int helpFind(int left,int right,vector<int>&nums){
        while(left>right){
            return -1;
        }
        int mid=left+((right-left)>>1);
        int leftNums=helpFind(left, mid-1, nums);
        if(leftNums!=-1){
            return leftNums;
        }
        if(nums[mid]==mid){
            return mid;
        }
        int rightNums=helpFind(mid+1,right,nums);
        return rightNums;
        
    }
    int findMagicIndex_BinarySearch(vector<int>& nums) {
        int len=(int)nums.size()-1;
        return helpFind(0, len, nums);
    }


};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
