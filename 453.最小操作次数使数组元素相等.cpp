#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int base = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res += nums[i] - base;
        }
        return res;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    Solution s;
    int res = s.minMoves(v);
    cout << res << endl;
    return 0;
}