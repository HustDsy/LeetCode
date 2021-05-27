//
//  main.cpp
//  810. 黑板异或游戏
//
//  Created by dsy on 2021/5/26.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        return xorsum == 0;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
