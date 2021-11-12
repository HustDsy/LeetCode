#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    static constexpr int mod  = 1000000007;
   public:
    // i< j && a[i] > a[j]
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = (j - 1 >= 0 ? dp[i][j - 1] : 0) - (j - i >= 0 ? dp[i - 1][j - i] : 0) + dp[i - 1][j];
                if (dp[i][j] >= mod) {
                    dp[i][j] -= mod;
                } else if (dp[i][j] < 0) {
                    dp[i][j] += mod;
                }
            }
        }
        return dp[n][k];
    }
};
