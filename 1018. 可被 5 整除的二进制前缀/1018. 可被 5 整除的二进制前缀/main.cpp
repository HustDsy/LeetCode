//
//  main.cpp
//  1018. 可被 5 整除的二进制前缀
//
//  Created by dsy on 2021/1/14.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>ans;
        int pre=0;
        for(int i=0;i<A.size();i++){
            pre=((pre<<1)+A[i])%5;
            ans.emplace_back(pre==0);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
