#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // 最小堆
        auto cmp = [&](pair<int, int> x, pair<int, int> y)->bool {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>q(cmp);
        for (int i = 1; i < arr.size(); i++) {
            q.emplace(0, i);
        }
        for (int i = 1; i < k; i++) {
            auto cur = q.top();
            q.pop();
            if (cur.first + 1 < cur.second) {
                q.emplace(cur.first + 1, cur.second);
            }
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};
