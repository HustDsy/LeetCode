//
//  main.cpp
//  392-判断子序列
//
//  Created by 董深育 on 2020/7/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool flag=true;
        int ret=0;
        for(int i=0;i<s.length();i++){
            ret=t.find_first_of(s[i],ret);
            if(ret>=0&&ret<t.length()){
                ret=ret+1;;
            }else{
                flag=false;
            }
        }
        return flag;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    bool ret=s.isSubsequence("abc","ahbgdc");
    return 0;
}
