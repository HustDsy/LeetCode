#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size();
        for (int i = 0; i < n && nums[i] < 0 && k > 0; i++) {
            nums[i] = -nums[i];
            k--;
        }
        sort(nums.begin(), nums.end(), less<int>());
        while (k > 0) {
            nums[0] = -nums[0];
            k--;
        }
        int res = accumulate(nums.begin(), nums.end(), 0);
        return res;
    }
};