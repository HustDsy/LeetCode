//
//  main.cpp
//  剑指 Offer 53 - I. 在排序数组中查找数字 I
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        //寻找左边界
        int lpos;
        int rpos;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            int cur=nums[mid];
            if(cur==target){
                right=mid-1;
            }else if(cur>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        lpos=mid;
        //寻找有边界
        left=0;
        right=nums.size()-1;
        while(left<=right){
            mid=left+(right-left)/2;
            int cur=nums[mid];
            if(cur==target){
                left=mid+1;
            }else if(cur>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        rpos=mid;
        return rpos-lpos+1;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
