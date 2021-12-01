#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        int cur = 1;
        int l = s.length();
        for (int  i = 0; i < l; i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                cur++;
                res = max(res, cur);
            } else {
                res = max(res, cur);
                cur = 1;
            }
        } 
        return res;

    }
};