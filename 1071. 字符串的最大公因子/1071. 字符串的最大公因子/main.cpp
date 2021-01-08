//
//  main.cpp
//  1071. 字符串的最大公因子
//
//  Created by dsy on 2021/1/8.
//


#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    inline int gcd(int a, int b) {return b == 0? a : gcd(b , a % b);}
       string gcdOfStrings(string str1, string str2) {
           if (str1 + str2 != str2 + str1) return "";
           return str1.substr(0, gcd(str1.size(), str2.size()));
       }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
