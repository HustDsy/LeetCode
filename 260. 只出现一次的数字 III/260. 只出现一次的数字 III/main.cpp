//
//  main.cpp
//  260. 只出现一次的数字 III
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int num:nums){
            bitmask ^= num;
        }

        int diff = bitmask & (-bitmask);
        int x = 0;
            for (int num:nums){
                if (num & diff){
                x ^= num;
                }
        }
        return {x, bitmask^x};
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
