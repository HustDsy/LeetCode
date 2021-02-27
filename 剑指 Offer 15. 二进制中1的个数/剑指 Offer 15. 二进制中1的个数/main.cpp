//
//  main.cpp
//  剑指 Offer 15. 二进制中1的个数
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
            if(n&1) res++;
            n>>=1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
