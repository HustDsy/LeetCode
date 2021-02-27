//
//  main.cpp
//  1004. 最大连续1的个数 III
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i=0,j=0,r=0;
        int len=A.size();
        while(j<len){
            if(A[j]||K){
                A[j++]?:K--;
            }else{
                A[i++]?:j++;
            }
            r=max(r,j-i);
        }
        return r;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
