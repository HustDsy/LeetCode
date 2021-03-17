//
//  main.cpp
//  1049. 最后一块石头的重量 II
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:

    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=sum>>1;
        int n=stones.size();
        //dp[i][j]表示可以最多达到多少的合适
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        int temp=stones[0];
        while(temp<=target){
            dp[0][temp]=stones[0];
            temp++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                if(stones[i]<j){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-stones[i]]+stones[i]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                //dp[i][j]=j>=stones[i]?max(dp[i-1][j],dp[i-1][j-stones[i]]+stones[i]):dp[i-1][j];
            }
        }
        return abs(sum-dp[n-1][target]*2);
    }
//    int lastStoneWeightII(vector<int>& stones)
//     {
//         int n = stones.size();  // 石头的数量
//         int sum = 0;            // 石头的重量和
//         for (auto i : stones)
//             sum += i;
//         int target = sum / 2;   // 石头重量和的一半（向下取整）
//         vector<int> dp(target + 1, 0);
//         dp[0] = 0;              // 初始化
//         // 第一层循环，遍历每个石头
//         for (int i = 0; i < n; i++)
//         {
//             int val = stones[i];// 第i个石头的重量
//             // 第二层循环，从后向前遍历每个背包容量
//             // 背包容量j >= 第i个石头的重量val，才能考虑是否选择第i个石头
//             for (int j = target; j >= val; j--)
//                 dp[j] = std::max(dp[j], dp[j-val] + val);
//         }
//         // 用容量尽可能接近总重量一半的背包去装尽可能多的石头
//         // 装剩下的一堆 - 背包里的， 就是粉碎后剩下的
//         return sum - dp[target] - dp[target];
//     }


};




int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> stones={57,32,40,27,35,61};
    s.lastStoneWeightII(stones);
    return 0;
}
