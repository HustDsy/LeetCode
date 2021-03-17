//
//  main.cpp
//  494. 目标和
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,0));
        dp[0][nums[0]+1000]=1;
        dp[0][-nums[0]+1000]+=1;
        for(int i=1;i<n;i++){
            int val=nums[i];
            for(int j=-1000;j<=1000;j++){
                //给加号
                dp[i][j+1000]=dp[i][j+1000]+(((j+1000-val>=0)&&(j+1000-val<=2000))?dp[i-1][j+1000-val]:0);
                dp[i][j+1000]=dp[i][j+1000]+(((j+1000+val>=0)&&(j+1000+val<=2000))?dp[i-1][j+1000+val]:0);
            }
        }
        return S>1000?0:dp[n-1][S+1000];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
