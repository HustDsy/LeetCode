//
//  main.cpp
//  459. 重复的子字符串
//
//  Created by 董深育 on 2020/8/24.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s,1)!=s.size();
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
