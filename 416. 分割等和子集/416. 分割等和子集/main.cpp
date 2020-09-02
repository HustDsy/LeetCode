//
//  main.cpp
//  416. 分割等和子集
//
//  Created by 董深育 on 2020/9/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        int len=(int)nums.size();
        vector<vector<int>>dp(len,vector<int>(target+1,false));
        if(nums[0]<target){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<=target;j++){
                if(nums[i]==j){
                    dp[i][j]=true;
                    continue;
                }
                else if(nums[i]<j){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else{//当j大于nums[i]的时候 第i个肯定不要，所以就等于dp[i-1][j]
                    dp[i][j]=dp[i-1][j];
                }
            }
            
        }
        return dp[len-1][target];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
