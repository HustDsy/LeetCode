//
//  main.cpp
//  1006. 笨阶乘
//
//  Created by dsy on 2021/4/1.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
    int clumsy(int N) {
        if(N<=2) return N;
        if(N==3) return 6;
        int sum=N*(N-1)/(N-2)+N-3;
        N-=4;
        while(N>=4){
            sum+=(-N*(N-1)/(N-2)+N-3);
            N-=4;
        }
        return sum-clumsy(N);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
