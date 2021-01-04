//
//  main.cpp
//  509. 斐波那契数
//
//  Created by dsy on 2021/1/4.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int fib(int n) {
        if(n==0||n==1) return n;
        int p=0;
        int q=1;
        for(int i=2;i<=n;i++){
            int temp=q;
            q=p+q;
            p=temp;
        }
        return q;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
