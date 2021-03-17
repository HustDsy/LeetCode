//
//  main.cpp
//  剑指 Offer 44. 数字序列中某一位的数字
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9)return n;
        //几位数
        int dight=1;
        //初始值是多少
        int start=1;
        while(true){
            int cur=pow(10,dight-1);
            long cc=(long)cur*9*dight;
            if(n>cc){
                n-=cc;
                dight+=1;
            }else{
                break;
            }
        }
        //说明目标返回值所在数的位数是dight 起始值为10^(dight-1)，当dight==1时返回0
        start=dight==1?0:pow(10,dight-1);
        //判断在第几个数
        int pos=n%dight;
        int curnum=pos==0?n/dight:n/dight+1;
        curnum=start+curnum-1;
        pos=dight-1-(n-1)%dight;
        //注意pos是从右像左数的
        int t=0;
        while(curnum){
            t=curnum%10;
            if(pos==0){
                break;
            }
            pos--;
            curnum=curnum/10;
        }
        return t;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    s.findNthDigit(100);
    return 0;
}
