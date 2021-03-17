//
//  main.cpp
//  剑指 Offer 62. 圆圈中最后剩下的数字
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
