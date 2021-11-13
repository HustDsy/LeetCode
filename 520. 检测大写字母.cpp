#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool big = true;
        bool small = true;
        bool first = isupper(word[0]);
        bool next = true;
        for (int i = 0; i < n; i++) {
            char cur = word[i];
            if (isupper(cur)) {
                small = false;
                if (i > 0) {
                    next = false;
                }
            } else {
                big = false;
            }
        }
        return small || big || (first && next);
    }
};