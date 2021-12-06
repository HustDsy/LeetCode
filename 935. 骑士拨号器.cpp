#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int knightDialer(int n) {
        int mod = 1000000000 + 7;
        // dp[i][j] 以i开始 j位数的可能性
        vector<vector<int>> dp(10, vector<int>(n + 1, 0));
        // 记录可以每个数字可以跳到的数字
        vector<vector<int>> can(10);
        can[0] = {4, 6};
        can[1] = {6, 8};
        can[2] = {7, 9};
        can[3] = {4, 8};
        can[4] = {3, 9, 0};
        can[5] = {};
        can[6] = {0, 7, 1};
        can[7] = {2, 6};
        can[8] = {1, 3};
        can[9] = {2, 4};
        for (int i = 0; i < 10; i++) {
            dp[i][1] = 1;
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i < 10; i++) {
                for (int k : can[i]) {
                    dp[i][j] =dp[i][j]%mod + dp[k][j - 1]% mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++) {
            res =(res%mod + dp[i][n]%mod)%mod;
        }
        return res;
    }
};

int main() {
    Solution s;
    int res = s.knightDialer(4);
    cout << 4 << endl;
    return 0;
}
