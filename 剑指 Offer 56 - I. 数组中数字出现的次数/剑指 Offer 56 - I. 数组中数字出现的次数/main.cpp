//
//  main.cpp
//  剑指 Offer 56 - I. 数组中数字出现的次数
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using  namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret=0;
        for(int n:nums){
            ret^=n;
        }
        int div=1;
        while((div&ret)==0){
            div<<=1;
        }
        int a=0;
        int b=0;
        for(int n:nums){
            if(div&n){
                a^=n;
            }else{
                b^=n;
            }
        }
        return vector<int>{a,b}
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
