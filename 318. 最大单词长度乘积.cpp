#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int l = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) -> bool {
            return a.length() < b.length();
        });
        vector<int> help(l, 0);
        for (int i = 0; i < l; i++) {
            string cur = words[i];
            for (int j = 0; j < cur.length(); j++) {
                help[i] |= (1 << (cur[j] - 'a'));
            }
        }
        vector<int> dp(l, -1);
        int res = -1;
        for (int i = l - 1; i >= 0; i--) {
            int j = i - 1;
            while (j >= 0 && dp[i] == -1) {
                if (!(help[i] & help[j])) {
                    dp[i] = words[i].length() * words[j].length();
                    dp[j] = dp[i];
                }
                j--;
            }
            res = max(res, dp[i]);
        }
        return res == -1 ? 0 : res;
    }
};

int main() {
    Solution solution;
    vector<string> words{"eae", "ea", "aaf", "bda",   "fcf",
                         "dc",  "ac", "ce",  "cefde", "dabae"};
    int res = solution.maxProduct(words);
}