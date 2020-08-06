//
//  main.cpp
//  136-只出现一次的数字
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //异或
        int max=0;
        int len=(int)nums.size();
        if(len==0){
            return 0;
        }
        nums.push_back(INT_MAX);
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            max=max^nums[i];
            if(nums[i]==nums[i+1]){
                i++;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
