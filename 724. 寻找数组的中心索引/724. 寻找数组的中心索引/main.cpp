//
//  main.cpp
//  724. 寻找数组的中心索引
//
//  Created by dsy on 2021/1/28.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=accumulate(nums.begin(), nums.end(), 0);
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(2*cur==ans-nums[i]){
                return i;
            }
            cur+=nums[i];
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here
    Solution s;
    vector<int>nums={1,7,3,6,5,6};
    s.pivotIndex(nums);
    return 0;
}
