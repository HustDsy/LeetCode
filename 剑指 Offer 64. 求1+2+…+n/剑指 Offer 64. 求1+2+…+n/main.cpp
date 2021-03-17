//
//  main.cpp
//  剑指 Offer 64. 求1+2+…+n
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int res=0;
    int sumNums(int n) {
        bool x=n>1&&sumNums(n-1)>0;
        res+=n;
        return res;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
