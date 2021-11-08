#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x_min = m;
        int y_min = n;
        map<int, int> vv;
        vv[1] = 1;
        for (auto& [x, y] : vv) {
            cout << x << " " << y << endl;
        }
        for (auto& v : ops) {
            x_min = min(x_min, v[0]);
            y_min = min(y_min, v[1]);
        }
        return x_min * y_min;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v{{1,2}};
    cout << s.maxCount(2, 2, v) << endl;
    return 0;
}