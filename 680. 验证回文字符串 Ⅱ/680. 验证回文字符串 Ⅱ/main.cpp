//
//  main.cpp
//  680. 验证回文字符串 Ⅱ
//
//  Created by dsy on 2021/3/23.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool check(string&s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;

    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return check(s,i+1,j)||check(s,i,j-1);
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
