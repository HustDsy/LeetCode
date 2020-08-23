//
//  main.cpp
//  47. 全排列 II
//
//  Created by 董深育 on 2020/8/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    //数组长度，flag判断数字是否访问过，
    void getRet(int size,vector<int>flag,vector<int>nums,int num){
        if(num==size){
            ret.emplace_back(temp);
            return;
        }
        for(int i=0;i<size;i++){
            if(flag[i]==0){
                if(i>0&&nums[i]==nums[i-1]&&flag[i-1]==1){
                    continue;
                }
                temp.emplace_back(nums[i]);
                flag[i]=1;
                getRet(size, flag, nums, num+1);
                flag[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size=static_cast<int>(nums.size());
        sort(nums.begin(),nums.end());
        vector<int>flag(size,0);
        getRet(size, flag, nums, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
