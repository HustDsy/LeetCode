//
//  main.cpp
//  137. 只出现一次的数字 II
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //真值表
    int singleNumber(vector<int>& nums) {
        int x=0;
        int y=0;
        for(int num:nums){
            x = ~y & (x ^ num);
            y = ~x & (y ^ num);
        }
        return x;
    }
};


int main(int argc, const char * argv[]) {
   
    std::cout << "Hello, World!\n";
    return 0;
}
