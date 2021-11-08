#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int l = secret.length();
        int A = 0, B = 0;
        vector<int> flag(l, 0);
        for (int i = 0; i < l; i++) {
            if (secret[i] == guess[i]) {
                A++;
                flag[i] = 1;
            } else {
                m[secret[i]]++;
            }
        }
        for (int i = 0; i < l; i++) {
            if (m.count(guess[i]) && m[guess[i]] > 0 && !flag[i]) {
                m[guess[i]]--;
                B++;
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