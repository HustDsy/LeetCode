#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26);
        for (char c : magazine) {
            int cur = c - 'a';
            v[cur]++;
        }
        for (char r : ransomNote) {
            int cur = r - 'a';
            v[cur]--;
            if (v[cur] < 0) {
                return false;
            }
        }
        return true;
    }
};
