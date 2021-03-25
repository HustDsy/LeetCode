//
//  main.cpp
//  76. 最小覆盖子串
//
//  Created by dsy on 2021/3/19.
//

#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = 0;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
        
                ++cnt[s[r]];
          
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
          
                    --cnt[s[l]];
             
                ++l;
            }
            r++;
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    s.minWindow("ADOBECODEBANC","ABC");
    return 0;
}
