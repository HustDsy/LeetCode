//
//  main.cpp
//  剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i=0;
        int l=nums.size();
        int j=l-1;
        while(i<j){
            //找到第一个偶数
            while(i<j&&(nums[i]&1)){
                i++;
            }
            //找到第一个奇数
            while(j>i&&!(nums[j]&1)){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        return  nums;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={1,2,3,4};
    s.exchange(nums);
    return 0;
}
