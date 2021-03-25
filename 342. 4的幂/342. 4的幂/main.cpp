//
//  main.cpp
//  342. 4的幂
//
//  Created by dsy on 2021/3/22.
//

#include <iostream>

class Solution {
public:
 bool isPowerOfFour(int num) {
    if (num < 0 || num & (num-1)){//check(is or not) a power of 2.
        return false;
    }
    return num & 0x55555555;//check 1 on odd bits
}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
