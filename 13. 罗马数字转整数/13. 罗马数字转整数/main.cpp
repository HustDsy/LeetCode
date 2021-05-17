//
//  main.cpp
//  13. 罗马数字转整数
//
//  Created by dsy on 2021/5/17.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        char cur;
        string t;
        int n=(int)s.size();
        for(int i=0;i<n;i++){
            cur=s[i];
            t.push_back(cur);
            if(cur=='I'){
                //判断后面有没有V，X
                if(i+1<n&&s[i+1]=='V'){
                    ans+=4;
                    i++;
                }else if(i+1<n&&s[i+1]=='X'){
                    ans+=9;
                    i++;
                }else{
                    ans+=1;
                }
            }else if(cur=='V'){
                ans+=5;
            }else if(cur=='X'){
                //判断后面有没有L，C
                if(i+1<n&&s[i+1]=='L'){
                    ans+=40;
                    i++;
                }else if(i+1<n&&s[i+1]=='C'){
                    ans+=90;
                    i++;
                }else{
                    ans+=10;
                }
            }else if(cur=='L'){
                ans+=50;
            }else if(cur=='C'){
                //判断有无DX
                  if(i+1<n&&s[i+1]=='D'){
                    ans+=400;
                    i++;
                }else if(i+1<n&&s[i+1]=='M'){
                    ans+=900;
                    i++;
                }else{
                    ans+=100;
                }
            }else if(cur=='D'){
                ans+=500;
            }else if(cur=='M'){
                ans+=1000;
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
