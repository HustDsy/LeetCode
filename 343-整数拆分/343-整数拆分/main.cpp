//
//  main.cpp
//  343-整数拆分
//
//  Created by 董深育 on 2020/7/30.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;


class Solution {
public:
    //记忆化递归，超出时间限制
    int integerBreak(int n) {
        int nums[n+1];
        for(int i=1;i<=n;i++){
            nums[i]=0;
        }
        return getIntegerBreak(n, nums);
     
    }
    int getIntegerBreak(int n,int nums[]){
        if(n==2||n==1){
            nums[n]=1;
            return nums[n];
        }
        int mid=n/2;
        for(int i=1;i<=mid;i++){
            if(nums[i]==0){
                nums[i]=integerBreak(i);
            }
            if(nums[n-i]==0){
                nums[n-i]=integerBreak(n-i);
            }
            int temp=max(i*(n-i),nums[i]*nums[n-i]);
            temp=max(i*nums[n-i],temp);
            temp=max((n-i)*nums[i],temp);
            nums[n]=max(nums[n],temp);
        }
        return nums[n];
    }
    //动态规划
     int integerBreak_DP(int n) {
         if(n==2){
             return 1;
         }
         int dp[n+1];
         dp[0]=0;
         dp[1]=0;
         dp[2]=1;
         for(int i=3;i<=n;i++){
             int temp=0;
             for(int j=2;j<i;j++){
                 temp=max(temp,max(j*(i-j),j*dp[i-j]));
             }
             dp[i]=temp;
         }
         return dp[n];
     }
};
int main(int argc, const char * argv[]) {
    Solution s;
    int ret=s.integerBreak(3);
    return 0;
}
