//
//  main.cpp
//  面试题 08.07. 无重复字符串的排列组合
//
//  Created by 董深育 on 2020/9/30.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<string>ret;
    void dfs(string S,vector<int>flag,int len,string trace){
        if(trace.length()==len){
            ret.emplace_back(trace);
            return;
        }
        for(int i=0;i<len;i++){
            if(flag[i])continue;
            flag[i]=1;
            dfs(S,flag,len,trace+S[i]);
            flag[i]=0;
        }
    }
    vector<string> permutation(string S) {
        int len=(int)S.length();
        vector<int>flag(len,1);
        dfs(S,flag,len,"");
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
