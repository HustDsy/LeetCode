//
//  main.cpp
//  剑指 Offer 67. 把字符串转换成整数
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int res=0;
        int sign=1;
        int n=str.length();
        if(n<0) return res;
        int i=0;
        //先找到第一个数字
        while(str[i]==' '){
            ++i;
            if(i==n){
                return res;
            }
        }
        //判断标点符号
        sign=str[i]=='-'?-1:1;
        int edge=214748364;
        if(str[i]=='-'||str[i]=='+'){
            ++i;
        }
        while(i<n){
            if(str[i]<'0'||str[i]>'9'){
                break;
            }
            int curnum=str[i]-'0';
            if(res>edge||(res==edge&&curnum>7)){
                return sign==1?INT_MAX:INT_MIN;
            }
            res=res*10+curnum;
            i++;
        }
        return res*sign;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
