#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<int> _nums;
    vector<int> cur;

   public:
    Solution(vector<int>& nums) {
        _nums = nums;
        cur.resize(nums.size());
        copy(nums.begin(), nums.end(), cur.begin());
    }

    vector<int> reset() {
        copy(cur.begin(), cur.end(), _nums.begin());
        return _nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < _nums.size(); ++i) {
            int j = i + rand() % (_nums.size() - i);
            swap(_nums[i], _nums[j]);
        }
        return _nums;
    }
};
