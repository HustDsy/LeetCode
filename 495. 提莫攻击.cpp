#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int n = timeSeries.size();
        for (int i = 0; i < n - 1; i++) {
            int cur = timeSeries[i] + duration - 1;
            if (cur < timeSeries[i + 1]) {
                res += duration;
            } else {
                res += timeSeries[i + 1] - timeSeries[i];
            }
        }
        res += duration;
        return res;
    }
};