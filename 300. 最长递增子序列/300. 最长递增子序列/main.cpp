//
//  main.cpp
//  300. 最长递增子序列
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1) return 1;
        vector<int>dp(n,1);
        dp[0]=1;
        int ans=dp[0];
        for(int i=1;i<=n-1;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums={10,9,2,5,3,7,101,18};
    s.lengthOfLIS(nums);
    std::cout << "Hello, World!\n";
    return 0;
}
