//
//  main.cpp
//  剑指 Offer 20. 表示数值的字符串
//
//  Created by 董深育 on 2020/9/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    /*
    在小数点之前不能出现e以及小数点，并且小数点的前面或者后面至少有一个跟着整数
    在e之前一定得有整数，并且不能有重复的1，后面跟着整数或者跟着+或者-号
    对于+号和-号，出现在第一位或者在e，E后面,而且不应该出现在最后一位
     */
    bool isNumber(string s) {
        int len=static_cast<int>(s.length());
        if(len==0){
            return false;
        }
        //把前面的空格去掉
        bool isNum=false;
        bool isE=false;
        bool isDot=false;
        bool isSpace=true;
        int begin=0;
        for(int i=0;i<len;i++){
            //前面出现的空格 全部continue
            if(s[i]==' '&&isSpace){
                begin++;
                continue;
            }
            if(s[i]!=' '){
                isSpace=false;
            }
            if(s[i]>='0'&&s[i]<='9'){
                isNum=true;
            }else if(s[i]=='.'){ //小数点的话 不能出现小数点 以及E和e,前面有整数或者后面有整数
                if(isE||isDot){
                    return false;
                }
                if((i+1==len||!(s[i+1]>='0'&&s[i+1]<='9'))&&!isNum){
                    return false;
                }
                isDot=true;
            }else if(s[i]=='E'||s[i]=='e'){
                //前面一定有整数而且不能有重复的e,或者后面跟着一个+-
                if(!isNum||isE){
                    return false;
                }
                //后面跟着的不是数字或者+ -都为错
                if(i+1==len||(!(s[i+1]>='0'&&s[i+1]<='9')&&!(i+1==len||s[i+1]=='+'||s[i+1]=='-'))){
                    return false;
                }
                isE=true;
            }else if(s[i]=='+'||s[i]=='-'){//+,-号只出现在第一位或者e的后面{
                if(i!=begin&&s[i-1]!='e'&&s[i-1]!='E'){
                    return false;
                }
                //最后一位的话 return
                if(i+1==len){
                    return false;
                }
            }else if(s[i]==' '&&!isSpace){//这是后面出现的空格
                while(s[i]==' '&&i<len){
                    i++;
                }
                //只有一种情况是对的 那就是i到末尾
                if(i!=len){
                    return false;
                }
                
            }else{
                return false;
            }
            
        }
        //全是空格的情况
        if(isSpace){
            return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string s=" 1111";

    return 0;
}
