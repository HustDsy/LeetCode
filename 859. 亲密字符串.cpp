#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        int ls = s.length();
        int gs = goal.length();
        if (ls != gs) {
            return false;
        }
        bool dou = false;
        set<char> check;
        for (char c : s) {
            if (check.count(c)) {
                dou = true;
                break;
            }
            check.insert(c);
        }
        if (s == goal) {
            return dou;
        }
        int a = -1, b = -1;
        for (int i = 0; i < ls; i++) {
            if (s[i] != goal[i]) {
                b = a == -1 ? -1 : a;
                a = i;
            }
        }
        if (a == -1 || b == -1) {
            return false;
        }
        swap(s[a], s[b]);
        return s == goal;
    }
};