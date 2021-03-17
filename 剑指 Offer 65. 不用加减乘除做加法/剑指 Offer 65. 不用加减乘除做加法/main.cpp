//
//  main.cpp
//  剑指 Offer 65. 不用加减乘除做加法
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        // 后续用a表示非进位和，b表示进位，当进位为0，则表示计算结束
        return b == 0 ? a : add(a^b, (unsigned int)(a&b) << 1);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
