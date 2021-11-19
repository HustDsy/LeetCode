#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    unordered_map<int, int> dp;
    int integerReplacement(int n) {
        if (n == 1) {
            dp[1] = 0;
            return 0;
        }
        if (dp.count(n)) {
            return dp[n];
        }
        if (!(n & 1)) {
            dp[n] = 1 + integerReplacement(n / 2);
            return dp[n];
        }
        dp[n] =
            2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        return dp[n];
    }
};