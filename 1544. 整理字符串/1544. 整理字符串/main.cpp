//
//  main.cpp
//  1544. 整理字符串
//
//  Created by 董深育 on 2020/8/11.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    char getA(char a){
        if(a>='a'&&a<='z'){
            return a-32;
        }else if(a>='A'&&a<='Z'){
            return a+32;
        }
        return a;
    }
    string makeGood(string s) {
        int len=(int)s.length();
        if(len==1||len==0){
            return s;
        }
        int i=0;
        int j=1;
        while(j<len){
            //如果一样 删除
            if(getA(s[i])==s[j]){
                s=s.substr(0,i)+s.substr(j+1,len-1-j);
                len=len-2;
                i=0;
                j=1;
            }else{
                i++;
                j++;
                
            }
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s="aAbc";
    Solution ss;
    s=ss.makeGood(s);
    return 0;
}
