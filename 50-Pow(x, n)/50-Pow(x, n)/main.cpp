//
//  main.cpp
//  50-Pow(x, n)
//
//  Created by 董深育 on 2020/7/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    //主要考虑 就是n=-2^31时，直接取反会溢出，这时候需要+1.将少乘的那一次最后计算
    double myPow(double x, int n) {
        if(x==1){
            return 1;
        }
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n==-1){
            return 1/x;
        }
        if(n<-1){
            return 1/(myPow(x,-(n+1))*x);
        }
        //类似于二分
        double ret=myPow(x,n/2);
        if(n%2==0){
            return ret*ret;
        }else{
            return ret*ret*x;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
