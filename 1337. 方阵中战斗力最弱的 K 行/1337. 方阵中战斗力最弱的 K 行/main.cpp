//
//  main.cpp
//  1337. 方阵中战斗力最弱的 K 行
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>mypair;
        int row=(int)mat.size();
        for(int i=0;i<=row-1;i++){
            int sum=accumulate(mat[i].begin(),mat[i].end(),0);
            mypair.push_back(make_pair(sum, i));
        }
        sort(mypair.begin(),mypair.end());
        vector<int>ret;
        for(int i=0;i<k;i++){
            ret.push_back(mypair[i].second);
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
