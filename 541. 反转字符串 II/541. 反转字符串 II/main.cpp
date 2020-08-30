//
//  main.cpp
//  541. 反转字符串 II
//
//  Created by 董深育 on 2020/8/30.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        int len=static_cast<int>(s.length());
        bool isReverse=true;
        string ret;
        string kk;
        for(int i=0;i<len;i++){
            if(isReverse){
                kk=s[i]+kk;;
            }else{
                kk=kk+s[i];
            }
            if((i+1)%k==0){
                isReverse=!isReverse;
                ret=ret+kk;
                kk="";
            }
        }
        ret+=kk;
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.reverseStr("abcdefg", 2)<<endl;
    return 0;
}
