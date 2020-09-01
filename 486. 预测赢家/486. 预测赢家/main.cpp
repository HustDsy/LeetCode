//
//  main.cpp
//  486. 预测赢家
//
//  Created by 董深育 on 2020/9/1.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //递归思路
    //begin，和end代表取的的数组 isA代表的是先手还是后手
    int getScore(int begin,int end,vector<int>&nums,int isA){
        if(begin==end){
            return isA*nums[end];
        }
        //取头端的数组
        int chooseBegin=nums[begin]*isA+getScore(begin+1, end, nums, -isA);
        //取尾端的情况
        int chooseEnd=nums[end]*isA+getScore(begin, end-1, nums, -isA);
        return max(chooseEnd*isA,chooseBegin*isA)*isA;
    }
    //记忆化递归
    vector<vector<int>>memo;
    int getScore_(int begin,int end,vector<int>&nums){
        if(memo[begin][end]){
            return memo[begin][end];
        }
        if(begin==end){
            return memo[begin][end]=nums[begin];
        }
        int pickBegin=nums[begin]-getScore_(begin+1, end, nums);
        int pickEnd=nums[end]-getScore_(begin, end-1, nums);
        return max(pickBegin,pickEnd);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        //return getScore(0, nums.size()-1, nums, 1)>=0;
        int len=static_cast<int>(nums.size());
        memo=vector<vector<int>>(len,vector<int>(len,0));
        return getScore_(0, len-1, nums)>=0;
    }
    //动态规划
    bool PredictTheWinner_(vector<int>& nums) {
        int length =(int)nums.size();
        auto dp = vector<vector<int>> (length, vector<int>(length));
        for (int i = 0; i < length; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] >= 0;
    }


};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
