//
//  main.cpp
//  415-字符串相加
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret="";
        int num1_int=0;
        int num2_int=0;
        int len1=(int)num1.length();
        int len2=(int)num2.length();
        int i=len1-1;int j=len2-1;
        int carryBit=0;
        int currBit=0;
        while(i>=0||j>=0){
            num1_int=i>=0?num1[i]-'0':0;
            num2_int=j>=0?num2[j]-'0':0;
            currBit=(num1_int+num2_int+carryBit)%10;
            carryBit=(num1_int+num2_int+carryBit)/10;
            ret=to_string(currBit)+ret;
            i--;
            j--;
        }
        if(carryBit!=0){
            ret=to_string(carryBit)+ret;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string ret=s.addStrings("0", "0");
    
    return 0;
}
