//
//  main.cpp
//  22. 括号生成
//
//  Created by 董深育 on 2020/8/20.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<string>ret;
    //回溯算发
    void dfs(int left,int right,string s){
        if(left==0&&right==0){
            ret.push_back(s);
            return;
        }
        if(left<0){
            return;
        }
        if(right<left){
            return;
        }
        dfs(left-1,right,s+"(");
        dfs(left,right-1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        dfs(n,n,s);
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
