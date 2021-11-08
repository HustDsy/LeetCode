#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;
        while (l <= r) {
            long  mid = (l + r) / 2;
            long res = mid * mid;
            if (res == num) {
                return true;
            } else if (res < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};