//
//  main.cpp
//  190. 颠倒二进制位
//
//  Created by dsy on 2021/3/29.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=32;
        uint32_t ans=0;
        while(i){
            ans|=(n&1)<<(i-1);
            n>>=1;
            i--;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    s.reverseBits((uint32_t)43261596);
    return 0;
}
