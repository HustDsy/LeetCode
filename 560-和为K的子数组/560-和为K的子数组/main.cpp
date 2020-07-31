//
//  main.cpp
//  560-和为K的子数组
//
//  Created by 董深育 on 2020/7/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //暴力法
  int subarraySum(vector<int>& nums, int k) {
        int length=(int)nums.size();
        int ret=0;
        for(int len=1;len<=length;len++){
            for(int j=0;j<=length-len;j++){
                int sums=0;
                int temp=len;
                while(temp>0){
                    sums+=nums[j+temp-1];
                    temp--;
                }
                if(sums==k){
                    ret+=1;
                }
            }
        }
        return ret;
    }
    //暴力解优化
    int subarraySum_New(vector<int>& nums, int k) {
            int count = 0;
            int len = nums.size();
            for (int left = 0; left < len; left++) {
                int sum = 0;
                // 区间里可能会有一些互相抵销的元素
                for (int right = left; right < len; right++) {
                    sum += nums[right];
                    if (sum == k) {
                        count++;
                    }
                }
            }
            return count;
        }

    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int>nums={1,1,1,};
    int ret=s.subarraySum(nums, 2);
    std::cout << "Hello, World!\n";
    return 0;
}
