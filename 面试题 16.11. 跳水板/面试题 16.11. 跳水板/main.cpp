//
//  main.cpp
//  面试题 16.11. 跳水板
//
//  Created by 董深育 on 2020/7/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k==0){
            return {};
        }
        vector<int>ret;
        for(int i=0;i<=k;i++){
            ret.push_back(shorter*i+(k-i)*longer);
        }
        sort(ret.begin(),ret.end());
        ret.erase(unique(ret.begin(),ret.end()), ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
