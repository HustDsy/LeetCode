//
//  main.cpp
//  面试题 08.09. 括号
//
//  Created by 董深育 on 2020/10/4.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string>ret;
    void dfs(int left,int right,string trace){
        if(left>right) return;
        if(left==0&&right==0){
            ret.emplace_back(trace);
        }
        //选择左括号
        if(left>=1){
            dfs(left-1,right,trace+"(");
        }
        //选择右括号
        if(right>=1){
            dfs(left,right-1,trace+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,n,"");
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.generateParenthesis(2);
    return 0;
}
