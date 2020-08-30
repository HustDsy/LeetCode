//
//  main.cpp
//  344. 反转字符串
//
//  Created by 董深育 on 2020/8/30.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin=0;
        int end=(int)s.size()-1;
        while(begin<end){
            int temp=s[begin];
            s[begin]=s[end];
            s[end]=temp;
            begin++;
            end--;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
