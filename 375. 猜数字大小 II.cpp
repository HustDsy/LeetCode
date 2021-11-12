#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMoneyAmount(int n) {
        // dp[i][j]表示在范围i，j一定赢的最小花费
        // dp[i][i]以及dp[i][j](j < i)都为0
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n ; j++) {
                int minCost = INT_MAX;
                for (int k = i; k < j; k++){
                    int cost = k + max(dp[i][k - 1], dp[k + 1][j]);
                    minCost = cost < minCost ? cost : minCost;
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][n];

    }
};