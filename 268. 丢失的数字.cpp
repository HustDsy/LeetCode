#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int sumn = n * (n + 1) / 2;
        int res = sumn - sum;
        return res;
    }
};