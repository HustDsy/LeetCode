//
//  main.cpp
//  231. 2 的幂
//
//  Created by dsy on 2021/5/31.
//

#include <iostream>
using namespace std;




class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return n&(n-1)?false:true;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
