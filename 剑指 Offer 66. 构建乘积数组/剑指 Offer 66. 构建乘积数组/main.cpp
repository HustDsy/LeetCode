//
//  main.cpp
//  剑指 Offer 66. 构建乘积数组
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int>b(n,1);
        for(int i=1;i<n;i++){
            b[i]=b[i-1]*a[i-1];
        }
        int tmp=1;
        for(int i=n-2;i>=0;i--){
            tmp*=a[i+1];
            b[i]*=tmp;
        }
        return b;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
