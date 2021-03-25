//
//  main.cpp
//  69. x 的平方根
//
//  Created by dsy on 2021/3/24.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long l=1;
        long r=x;
        while(l<=r){
            long mid=l+(r-l)/2;
            long cur=mid*mid;
            if(cur==x){
                return mid;
            }else if(cur>x){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l-1;
 
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
