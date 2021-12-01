#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    int findNthDigit(int n) {
        long nn = n;
        long cur = 1;
        long bits = 1;//判断在几位数
        long next = n;//判断在开头的第几个数
        while (nn > 0) {
            nn -= cur * 9 * bits;
            if (nn > 0) {
                next = nn;
                bits++;
            }
            cur *= 10;
        }
        // 表示以10^(bits - 1）开头的第next数字
        long begin = pow(10, bits - 1);
        long digit = begin + (next - 1) / bits;
        string s = to_string(digit);
        int i = (next - 1) % bits;
        return s[i] - '0';
    }
};