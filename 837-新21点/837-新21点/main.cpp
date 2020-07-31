//
//  main.cpp
//  837-新21点
//
//  Created by 董深育 on 2020/7/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    //dp[x]代表得分为x时的获胜概率
    double new21Game(int N, int K, int W) {
        double dp[K+W];
        double s=0;
        for(int i=K;i<K+W;i++){
            dp[i]=i>N?0:1;
            s+=dp[i];
        }
        for(int j=K-1;j>=0;j--){
            dp[j]=s/W;
            s=s-dp[j+W]+dp[j];
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
