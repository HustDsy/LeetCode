//
//  main.cpp
//  7. 整数反转
//
//  Created by 董深育 on 2020/8/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            int tmp=x%10;
            if(res>214748364||(res==21478364&&res>7)){
                return 0;
            }
            //判断是否 小于 最小32位整数
            if (res<-214748364 || (res==-214748364 && tmp<-8)) {
                return 0;
            }
            res = res*10 + tmp;
            x /= 10;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.reverse(123);
    return 0;
}
