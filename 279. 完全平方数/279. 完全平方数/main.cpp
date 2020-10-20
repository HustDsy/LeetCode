//
//  main.cpp
//  279. 完全平方数
//
//  Created by 董深育 on 2020/10/19.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        vector<int>nums;
        for(int i=0;i<=sqrt(n);i++){
            dp[i*i]=1;
            nums.emplace_back(i*i);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<nums.size();j++){
                if(dp[i]==1)break;
                if(nums[j]>=i)break;
                dp[i]=min(dp[i],dp[i-nums[j]]+1);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.numSquares(12);
    return 0;
}
