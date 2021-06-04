//
//  main.cpp
//  461. 汉明距离
//
//  Created by dsy on 2021/5/27.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int bitcount(int n){
        n = (n &0x55555555) + ((n >>1) &0x55555555) ;
        n = (n &0x33333333) + ((n >>2) &0x33333333) ;
        n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ;
        n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ;
        n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ;
        return n;
    }
    int hammingDistance(int x, int y) {
        int z=x^y;
        //看z有几个1
       return bitcount(z);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
