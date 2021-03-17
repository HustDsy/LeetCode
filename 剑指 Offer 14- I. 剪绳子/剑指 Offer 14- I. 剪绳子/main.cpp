//
//  main.cpp
//  剑指 Offer 14- I. 剪绳子
//
//  Created by dsy on 2021/2/27.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n==1||n==2) return 1;
        vector<int>dp(n+1,0);
        dp[1]=dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=2;j<i;j++){
                dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
