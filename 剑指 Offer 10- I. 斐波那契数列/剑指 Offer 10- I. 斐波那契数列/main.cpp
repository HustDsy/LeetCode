//
//  main.cpp
//  剑指 Offer 10- I. 斐波那契数列
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
using namespace std;


class Solution {
public:
    int  dp[101];
    Solution(){
        for(int i=0;i<101;i++){
            dp[i]=-1;
        }
    }
    int fib(int n) {
        if(dp[n]!=-1) return dp[n];
        if(n==0||n==1){
            dp[n]=n;
            return n;
        }
        if(n==2){
            dp[n]=1;
            return 1;
        }
        dp[n]=(fib(n-1)+fib(n-2))%(1000000007);
        return dp[n]%(1000000007);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
