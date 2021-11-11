#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // 以x为结尾 等差值为difference的最长的长度
        unordered_map<int, int> m;
        int res = -1;
        for (int num : arr) {
            int cur = num - difference;
            if (m.count(cur)) {
                m[num] = m[cur] + 1;
            } else {
                m[num] = 1;
            }
            res = max(m[num], res);
        }
        return res;
    }
};