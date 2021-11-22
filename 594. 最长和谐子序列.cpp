#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;
        for (int n : nums) {
            m[n]++;
        }
        int res = 0;
        for (auto [x, y] : m) {
            if (m.count(x + 1)) {
                res = max(res, y + m[x + 1]);
            }   
        }
        return res;
    }
};