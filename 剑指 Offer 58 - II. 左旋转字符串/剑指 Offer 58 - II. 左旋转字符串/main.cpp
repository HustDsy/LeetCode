//
//  main.cpp
//  剑指 Offer 58 - II. 左旋转字符串
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n - 1);
        reverse(s, n, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }
    void reverse(string& str, int begin, int end)
    {
        char temp;
        while(begin < end)
        {
            temp = str[begin];
            str[begin] = str[end];
            str[end] = temp;
            ++begin;
            --end;
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
