#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res("");
        for (char c : s) {
            if (c == ' ') {
                k--;
                if (k==0) {
                    break;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
