//
//  main.cpp
//  20. 有效的括号
//
//  Created by 董深育 on 2020/8/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    char getPair(char a){
        if(a=='}'){
            return '{';
        }else if(a==')'){
            return '(';
        }else if(a==']'){
            return '[';
        }
        return ' ';
    }
    bool isValid(string s) {
        stack<char>mystack;
        int len=(int)s.length();
        if(len==0){
            return true;
        }
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                mystack.push(s[i]);
            }else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(mystack.empty()){
                    return false;
                }else{
                    char top=mystack.top();
                    //如果相等的话
                    if(top==getPair(s[i])){
                        mystack.pop();
                    }else{
                        return false;
                    }
                }
            }
            
        }
        if(mystack.empty()){
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.isValid("()");
    return 0;
}
