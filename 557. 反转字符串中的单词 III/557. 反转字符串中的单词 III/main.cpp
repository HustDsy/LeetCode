//
//  main.cpp
//  557. 反转字符串中的单词 III
//
//  Created by 董深育 on 2020/8/30.
//  Copyright © 2020 董深育. All rights reserved.
//


#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=static_cast<int>(s.length());
        string ret;
        if(len==0||len==1){
            return s;
        }
        string kk;
        for(int i=0;i<len;i++){
            if(s[i]!=' '){
                kk=s[i]+kk;
            }else{
                ret+=kk;
                kk="";
                ret=ret+' ';
            }
        }
        ret=ret+kk;
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.reverseWords("Let's take LeetCode contest")<<endl;
    
    return 0;
}
