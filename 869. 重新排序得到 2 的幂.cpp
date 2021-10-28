#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> v;
    int l;
    bool isPowerOfTwo(int n) { return (n & (n - 1)) == 0; }

    /*
    s: 调整之前的数字
    idx: 已经选了多少个数字
    num: 当前数字
    */
    bool dfs(string& s, int idx, int num) {
        if (idx == l) {
            return isPowerOfTwo(num);
        }

        for (int i = 0; i < l; i++) {
            if ((num == 0 && s[i] == '0') || v[i] ||
                (i > 0 && !v[i - 1] && s[i - 1] == s[i])) {
                continue;
            }
            v[i] = 1;
            if (dfs(s, idx + 1, num * 10 + s[i] - '0')) {
                return true;
            }
            v[i] = 0;
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        l = s.length();
        v = vector<int>(l, 0);
        return dfs(s, 0, 0);
    }
};

int main() { return 0; }