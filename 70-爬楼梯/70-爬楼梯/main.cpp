//
//  main.cpp
//  70-爬楼梯
//
//  Created by 董深育 on 2020/6/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2){
            return n;
        }
        int first=1;
        int second=2;
        int third=0;
        for(int i=2;i<n;i++){
            third=first+second;
            first=second;
            second=third;
        }
        return third;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    int num;
    cin>>num;
    cout<<s.climbStairs(num);
    return 0;
}
