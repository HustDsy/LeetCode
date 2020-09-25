//
//  main.cpp
//  面试题 17.19. 消失的两个数字
//
//  Created by 董深育 on 2020/9/25.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int miss1=0;
        int miss2=0;
        int len=(int)nums.size();
        int n=len+2;
        long sum=n*(n+1)/2;
        long mul=long(n)*long((n+1))*long((2*n+1))/6;
        long s=0;
        long m=0;
        for(int i=0;i<len;i++){
            s+=nums[i];
            m+=nums[i]*nums[i];
        }
        long t1=sum-s;
        long t2=mul-m;
        miss1=(t1+sqrt(2*t2-t1*t1))/2;
        miss1=int(miss1);
        miss2=t1-miss1;
        return {miss1,(int)miss2};
    }
};

int main(int argc, const char * argv[]) {
    vector<int>nums={};
    return 0;
}
