#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod  = 1337;
    int pow(int x, int n) { 
        if (n == 0) return 1;
        if (n == 1) return x;
        long cur  = pow(x, n/2) % mod;
        if (n % 2) {
            return (long)x * cur * cur  % mod;
        } 
        return  cur * cur % mod;
    }
     int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int e: b) {
            ans = (long) pow(ans, 10) * pow(a, e) % mod;
        }
        return ans;
    }
};