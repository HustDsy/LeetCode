#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string getHint(string secret, string guess) {
        vector<int> nums(10, 0);
        int l = secret.length();
        int A = 0, B = 0;
        for (int i = 0; i < l; i++) {
            if (secret[i] == guess[i]) {
                A++;
            } else  {
                if (nums[guess[i] - '0']-- > 0) {
                    B++;
                }
                
                if (nums[secret[i] - '0']++ < 0) {
                    B++;
                }
            }
        }
        string res = to_string(A) + 'A' + to_string(B) + 'B';
        return res;
    }
};

int main () {
    int a = 0;
    if (a++ > 0) {
        cout << "++ first" << endl;
    } else {
        cout << "> first" << endl;
    }
    cout << a << endl;
    return 0;
}