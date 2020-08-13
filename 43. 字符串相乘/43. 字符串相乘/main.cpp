//
//  main.cpp
//  43. 字符串相乘
//
//  Created by 董深育 on 2020/8/13.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //num1相加
    string add(string num1,string num2){
        int len1=(int)num1.length();
        int len2=(int)num2.length();
        string ret="";
        int carrybit=0;
        int currbit=0;
        int i=len1-1;
        int j=len2-1;
        while(i>=0||j>=0){
            int bit1=i>=0?num1[i]-'0':0;
            int bit2=j>=0?num2[j]-'0':0;
            currbit=(bit1+bit2+carrybit)%10;
            carrybit=(bit1+bit2+carrybit)/10;
            ret=to_string(currbit)+ret;
            i--;
            j--;
        }
        if(carrybit!=0){
            ret=to_string(carrybit)+ret;
        }
        return ret;
    
    }
    string multiply(string num1, string num2) {
        if(atoi(num1.c_str())==0||atoi(num2.c_str())==0){
            return "0";
        }
        int len=num1.length();
        int len2=num2.length();
        if(len<len2){
            return multiply(num2, num1);
        }
        int j=len2-1;
        string ret="0";
       int currbit=0;
        int carrybit=0;
        while(j>=0){
            //当前乘法的结果
            string temp="";
            currbit=0;
            carrybit=0;
            //乘法
            for(int i=len-1;i>=0;i--){
                //取余
                int kk=(num2[j]-'0')*(num1[i]-'0')+carrybit;
                currbit=kk%10;
                //取整
                carrybit=kk/10;
                //
                temp=to_string(currbit)+temp;
            }
            if(carrybit!=0){
                 temp=to_string(carrybit)+temp;
            }
            //temp加0
            int zeronum=len-j-1;
            for(int i=0;i<zeronum;i++){
                temp+="0";
            }
            //对ret进行处理
            ret=add(ret,temp);
            j--;
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    string num=s.multiply("999", "999");
    return 0;
}
