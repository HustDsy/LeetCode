//
//  main.cpp
//  189. 旋转数组
//
//  Created by dsy on 2021/1/8.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reserve(vector<int>&nums,int begin,int end){
        for(int i=begin;i<=(begin+end-1)/2;i++){
            int temp=nums[i];
            nums[i]=nums[begin+end-i];
            nums[begin+end-i]=temp;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if(!len||len==1) return;
        k=k%len;
        reserve(nums, 0, len-1);
        reserve(nums, 0, k-1);
        reserve(nums, k, len-1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
