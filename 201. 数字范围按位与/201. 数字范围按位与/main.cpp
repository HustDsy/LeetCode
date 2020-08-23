//
//  main.cpp
//  201. 数字范围按位与
//
//  Created by 董深育 on 2020/8/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;


class Solution {
public:
    //寻找公共前缀
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            i++;
        }
        return m<<i;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.rangeBitwiseAnd(0, 1);
    return 0;
}
