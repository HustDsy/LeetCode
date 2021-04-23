//
//  main.cpp
//  263. 丑数
//
//  Created by dsy on 2021/4/10.
//

#include <iostream>

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        while(n%2==0){
            n=n/2;
        }
        while(n%3==0){
            n=n/3;
        }
        while(n%5==0){
            n=n/5;
        }
        return n==1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
