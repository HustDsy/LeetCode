//
//  main.cpp
//  剑指 Offer 16. 数值的整数次方
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
using namespace std;

class Solution {
public:
   double myPow(double x, int n) {
        if(x==1){
            return 1;
        }
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n==-1){
            return 1/x;
        }
        if(n<-1){
            return 1/(myPow(x,-(n+1))*x);
        }
        //类似于二分
        double ret=myPow(x,n/2);
        if(n%2==0){
            return ret*ret;
        }else{
            return ret*ret*x;
        }
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    
    cout<<s.myPow(0.00001, 2147483647)<<endl;
    return 0;
}
