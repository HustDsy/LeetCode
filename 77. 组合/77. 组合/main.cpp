//
//  main.cpp
//  77. 组合
//
//  Created by 董深育 on 2020/8/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int>kk;
    vector<vector<int>>ret;
    
    void getRet(int num,int k,int n,int begin){
        if(num==k){
            ret.emplace_back(kk);
            return;
        }
        for(int i=begin;i<=n;i++){
            kk.emplace_back(i);
            getRet(num+1, k, n, i+1);
            kk.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        getRet(0, k, n, 1);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
