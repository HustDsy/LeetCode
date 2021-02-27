//
//  main.cpp
//  剑指 Offer 10- II. 青蛙跳台阶问题
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        int  a=1;
        int b=1;
        int temp;
        for(int i=0;i<n;i++){
            temp=(a+b)%(1000000007);
            a=b;
            b=temp;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
