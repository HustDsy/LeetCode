//
//  main.cpp
//  779. 第K个语法符号
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
using namespace std;



class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(n==2) return k==1?0:1;
        if(kthGrammar(n-1,(k+1)/2)==0){
            return k%2==0?1:0;
        }else{
            return k%2==0?0:1;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
