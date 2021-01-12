//
//  main.cpp
//  5634. 删除子字符串的最大得分
//
//  Created by dsy on 2021/1/10.
//

#include <iostream>
#include<string>
using  namespace std;


class Solution {
private:
    int ans = 0;
public:
    void getab(string& s, int x) {
        string t;
        for (char c: s) {
            t.push_back(c);
            while (t.size() >= 2 && t[t.size() - 2] == 'a' && t[t.size() - 1] == 'b') {
                ans += x;
                t.pop_back();
                t.pop_back();
            }
        }
        s = move(t);
    }
    
    void getba(string& s, int x) {
        string t;
        for (char c: s) {
            t.push_back(c);
            while (t.size() >= 2 && t[t.size() - 2] == 'b' && t[t.size() - 1] == 'a') {
                ans += x;
                t.pop_back();
                t.pop_back();
            }
        }
        s = move(t);
    }

    int maximumGain(string s, int x, int y) {
        if (x >= y) {
            getab(s, x);
            getba(s, y);
        }
        else {
            getba(s, y);
            getab(s, x);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
