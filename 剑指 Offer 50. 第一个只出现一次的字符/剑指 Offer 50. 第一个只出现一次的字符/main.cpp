//
//  main.cpp
//  剑指 Offer 50. 第一个只出现一次的字符
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int>m;
        int l=s.length();
        for(int i=0;i<l;i++){
            m[s[i]]+=1;
        }
        for(int i=0;i<l;i++){
            if(m[s[i]]==1){
                return s[i];
            }
        }
        return ' ';
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
