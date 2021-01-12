//
//  main.cpp
//  400. 第 N 位数字
//
//  Created by dsy on 2021/1/12.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        //确定n在几位数的区间范围内
        /*bit num
          1   9
          2   90
          3   900
         */
        long long bit=1;
        //long long num=9;
        while(n-9*pow(10,bit-1)*bit>0){
            n=n-9*pow(10,bit-1)*bit;
            bit++;
        }
        //确定n在第几位数,n从1开始所以n-1
        int num=pow(10,bit-1)+(n-1)/bit;
        //pos 表示在这个数字的第几位
        int pos=n%bit==0?bit:n%bit;
        //得到这个整数的第pos位置，从左到右，从1开始
        int t = pow(10, bit - pos);
        return num / t % 10;
      
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.findNthDigit(1000);
    return 0;
}
