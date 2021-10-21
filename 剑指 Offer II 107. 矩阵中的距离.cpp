#include <bits/stdc++.h>
using namespace std;

#define MAX 100000;

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(mat);
         
        // 左上角
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j]) {
                    // left & top
                    int left = j > 0 ? dp[i][j - 1] : MAX;
                    int top = i > 0 ? dp[i - 1][j] : MAX;
                    dp[i][j] =  1 + min(left, top);
                }
            }
        }
        
        // 右下角
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (dp[i][j]) {
                    // right & down
                    int right = j < n -1 ? dp[i][j + 1] : MAX;
                    int down = i < m - 1 ? dp[i + 1][j] : MAX;
                    dp[i][j] = min(dp[i][j], 1 + min(right, down));
                }
            }
        }
        return dp;
    }
};
