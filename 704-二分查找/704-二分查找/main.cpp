//
//  main.cpp
//  704-二分查找
//
//  Created by 董深育 on 2020/7/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=(int)nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                return mid;
            }else if(target<nums[mid]){
                right=mid-1;
            }else if(target>nums[mid]){
                left=mid+1;
            }
            
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int num=s.search(<#vector<int> &nums#>, <#int target#>)
    return 0;
}
