//
//  main.cpp
//  剑指 Offer 57. 和为s的两个数字
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                return vector<int>{nums[l],nums[r]};
            }else if(nums[l]+nums[r]>target){
                r--;
            }else{
                l++;
            }
        }
        return {};
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
