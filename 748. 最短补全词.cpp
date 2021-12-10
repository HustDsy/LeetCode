#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& v, string& s) {
        // 判断s是不是包含p
        vector<int> vv(26);
        for (char c : s) {
            vv[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] == 0) continue;
            if (v[i] > vv[i]) {
                return false;
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> v(26);
        for (char c : licensePlate) {
            if (islower(c) || isupper(c)) {
                v[tolower(c) - 'a']++;
            }
        }
        string res("");
        int size = INT_MAX;
        for (string s : words) {
            if (check(v, s) && s.length() < size) {
                size = s.length();
                res = s;
            }
        }
        return res;
    }
};