#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // unordered_map<int, int> m;
        // priority_queue<int, vector<int>, less<int>> q;
        // int n = score.size();
        // for (int i = 0; i < n; i++) {
        //     m[score[i]] = i;
        //     q.push(score[i]);
        // }
        // vector<string>res(n, " ");
        // unordered_map<int, string> mm;
        // mm[1] = "Gold Medal";
        // mm[2] = "Silver Medal";
        // mm[3] = "Bronze Medal";
        // for (int j = 4; j <= n; j++) {
        //     mm[j] = to_string(j);
        // }
        // int k = 1;
        // while (!q.empty()) {
        //     int cur = q.top();
        //     q.pop();
        //     res[m[cur]] = mm[k];
        //     k++;
        // }
        // return res;
        int n = score.size();
        vector<int> order(n, 0);
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(),
             [&score](const int& a, const int& b) -> bool {
                 return score[a] > score[b];
             });
        vector<string> res(n, string());
        for (int i = 0; i < n; i++) {
            switch (i) {
                case 0:
                    res[order[i]] = "Gold Medal";
                    break;
                case 1:
                    res[order[i]] = "Silver Medal";
                    break;
                case 2:
                    res[order[i]] = "Bronze Medal";
                    break;
                default:
                    res[order[i]] = to_string(i + 1);
                    break;
            }
        }
        return res;
    }
};