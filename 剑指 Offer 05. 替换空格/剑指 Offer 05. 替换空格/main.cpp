//
//  main.cpp
//  剑指 Offer 05. 替换空格
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string t("");
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                t+="%20";
            }else{
                t+=s[i];
            }
        }
        return t;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
