//
//  main.cpp
//  191. 位1的个数
//
//  Created by dsy on 2021/3/22.
//

#include <iostream>
using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t res=0;
        //二进制进分界
        res=(n>>1&0x55555555)+(n&0x55555555);
        res=(res>>2&0x33333333)+(res&0x33333333);
        res=(res>>4&0x0f0f0f0f)+(res&0x0f0f0f0f);
        res=(res>>8&0x00ff00ff)+(res&0x00ff00ff);
        res=(res>>16&0x0000ffff)+(res&0x0000ffff);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.hammingWeight(11);
    return 0;
}
