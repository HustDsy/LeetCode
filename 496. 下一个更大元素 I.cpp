#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() &&  nums2[i] > s.top()) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            int cur = s.top();
            m[cur] = -1;
            s.pop();
        }
        vector<int> res;
        res.resize(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }
        return res;
    }
};