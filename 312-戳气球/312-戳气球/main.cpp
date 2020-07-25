//
//  main.cpp
//  312-戳气球
//
//  Created by 董深育 on 2020/7/25.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    //递归，超出时间限制
    /*
    int maxCoins(vector<int>& nums) {
        int len=(int)nums.size();
        if(len==0){
            return 0;
        }
        if(len==1){
            return nums[0];
        }
        if(len==2){
            return max(nums[0]*nums[1]+nums[0],nums[0]*nums[1]+nums[1]);
        }
        int ret=0;
        for(int i=0;i<len;i++){
            vector<int>temp=nums;
            vector<int>::iterator it=temp.begin();
            advance(it, i);
            temp.erase(it);
            int count=0;
            if(i==0){
                count=nums[i]*nums[i+1];
            }else if(i==len-1){
                count=nums[i-1]*nums[i];
            }else{
                count=nums[i-1]*nums[i]+nums[i+1];
            }
            ret=max(ret,maxCoins(temp)+count);
        }
        return ret;
    }
     */
    //动态规划
    int maxCoins(vector<int>& nums) {
        int n=(int)nums.size();
        int len=(int)nums.size()+2;
        vector<int>myNums(len);
        for(int i=0;i<len;len++){
            if(i==0||i==len-1){
                myNums[i]=1;
                continue;
            }
            myNums[i]=nums[i-1];
        }
        int dp[len][len];
        for(int i=0;i<len;i++){
            for(int j=0;i<len;j++){
                dp[i][j]=0;
            }
        }
        // 开始状态转移
        // i 应该从下往上
        for (int i = n; i >= 0; i--) {
            // j 应该从左往右
            for (int j = i + 1; j < n + 2; j++) {
                // 最后戳破的气球是哪个？
                for (int k = i + 1; k < j; k++) {
                    // 择优做选择
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + myNums[i]*myNums[j]*myNums[k]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int>nums={7,9,8,0,7,1,3,5,5,2};
    int ret=s.maxCoins(nums);
    return 0;
}
