//
//  main.cpp
//  剑指 Offer 49. 丑数
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n,0);
        dp[0]=1;
        int a=0,b=0,c=0;
        for(int i=1;i<n;i++){
            int cur=min(min(dp[a]*2,dp[b]*3),dp[c]*5);
            dp[i]=cur;
            if(cur==dp[a]*2){
                a++;
            }
            if(cur==dp[b]*3){
                b++;
            }
            if(cur==dp[c]*5){
                c++;
            }
        }
    return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
