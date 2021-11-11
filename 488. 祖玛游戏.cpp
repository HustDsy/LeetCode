#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int INF = 0x3f3f3f3f;
    string b; // 手上的球
    int m; // 球的个数
    unordered_map<string, int> map;

    int dfs(string &a, int cur) {
        if (a.length() == 0) return 0;
        if (map.count(a)) return map[a];
        int ans = INF;
        int n = a.length();
        for (int i = 0; i < m; i++) {
            if (((cur >> i) & 1) == 1) continue;
            int next  = (1 << 1) | cur;
            for (int j = 0; j <= n; j++) {
                string s = "";
                s += a.substr(0, j) + b[i];
                if (j != n) {
                    s += a.substr(j);
                }
                int k = j;
                while (0 <= k && k < s.length()) {
                    char c = s[k];
                    int l = k, r =k;
                    while (l >= 0 && s[l] == c) l--;
                    while (r < s.length() && s[r] == c) r++;
                    if (r - l + 1 >= 3) {
                        s.erase(l + 1, r - l - 1);
                        k = l >=0 ? l : r;
                    } else {
                        break;
                    }
                }
                ans = min(ans, dfs(s, next)) + 1;
            }
        }
        map[a] = ans;
        return ans;
    }

    int findMinStep(string board, string hand) {
        b = hand;
        m = hand.length();
        int res = dfs(b, 1 << m);
        return res == INF ? -1 : res;
    }
};