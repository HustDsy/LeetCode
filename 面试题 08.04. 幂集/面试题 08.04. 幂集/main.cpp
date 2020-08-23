//
//  main.cpp
//  面试题 08.04. 幂集
//
//  Created by 董深育 on 2020/8/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>kk={};
        vector<vector<int>>ret;
        ret.emplace_back(kk);
        for(int i=0;i<nums.size();i++){
            int len=static_cast<int>(ret.size());
            for(int j=0;j<len;j++){
                vector<int>temp=ret[j];
                temp.emplace_back(nums[i]);
                ret.emplace_back(temp);
            }
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>nums={1,2,3};
    s.subsets(nums);
    return 0;
}
