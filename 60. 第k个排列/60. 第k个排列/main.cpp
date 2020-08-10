//
//  main.cpp
//  60. 第k个排列
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //回溯算法
    vector<int>trace;
    int factorial(int n){
        
        int res = 1;
        while (n > 0) {
            res *= n--;
        }
        return res;
    }
    vector<int>dfs(int n,int k,vector<int>trace){
        if(trace.size()==n){
            return trace;
        }
        int cur=factorial(n-(int)trace.size()-1);
        for(int i=1;i<=n;i++){
            if(find(trace.begin(), trace.end(), i)!=trace.end()){
                continue;
            }
            if(k>cur){
                k-=cur;
                continue;
            }
            trace.push_back(i);
            return dfs(n,k,trace);
        }
        return {};
    }
    string getPermutation(int n, int k) {
        vector<int>num;
        trace=dfs(n,k,num);
        string res="";
        for(int i=0;i<trace.size();i++){
            res+=to_string(trace[i]);
        }
        return res;
    }
 
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    s.getPermutation(4, 9);
    std::cout << "Hello, World!\n";
    return 0;
}
