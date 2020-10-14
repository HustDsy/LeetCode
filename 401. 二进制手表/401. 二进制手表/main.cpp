//
//  main.cpp
//  401. 二进制手表
//
//  Created by 董深育 on 2020/10/14.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    inline int get1(int y){
        int x=y;
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
        x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
        return x;
    }
    vector<string> readBinaryWatch(int num) {
        //统计0-11的1的数量
        vector<string>ans;
        vector<int>minute(12,0);
        vector<int>second(60,0);
        for(int i=0;i<12;i++){
            minute[i]=get1(i);
            second[i]=minute[i];
        }
        //统计0-59的1个数量
        for(int i=12;i<60;i++){
            second[i]=get1(i);
        }
        for(int i=0;i<=11;i++){
            int num1=minute[i];
            if(num1>num) continue;;
            for(int j=0;j<=59;j++){
                int num2=second[j];
                if(num1+num2==num){
                    string num1s,num2s;
                    num1s=to_string(i);
                    if(j<10){
                        num2s="0"+to_string(j);
                    }else{
                        num2s=to_string(j);
                    }
                    ans.emplace_back(num1s+":"+num2s);
                }
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    s.readBinaryWatch(1);
    return 0;
}
