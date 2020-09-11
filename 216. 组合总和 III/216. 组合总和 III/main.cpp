//
//  main.cpp
//  216. 组合总和 III
//
//  Created by 董深育 on 2020/9/11.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    //相加之和为n的k个数
    void dfs(int begin,int k,int n){
        if(k==0&&n!=0){
            return;
        }
        for(int i=begin;i<=9;i++){
            if(n<i){
                return;
            }else if(n>i){
                temp.emplace_back(i);
                dfs(i+1,k-1,n-i);
                temp.pop_back();
            }else if(n==i){
                if(k==1){
                    temp.push_back(i);
                    ret.emplace_back(temp);
                    temp.pop_back();
                    return;
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k<=0){
            return {};
        }
        dfs(1,k,n);
        return ret;

    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>ret=s.combinationSum3(3, 9);
    return 0;
}
