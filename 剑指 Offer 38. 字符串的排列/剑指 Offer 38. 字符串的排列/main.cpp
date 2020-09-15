//
//  main.cpp
//  剑指 Offer 38. 字符串的排列
//
//  Created by 董深育 on 2020/9/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string>ret;
    string temp;
    void dfs(string&s,int len,vector<int>flag){
        if(temp.length()==len){
            ret.push_back(temp);
            return;
        }
        for(int i=0;i<len;i++){
            if(i>0&&flag[i-1]&&s[i]==s[i-1])continue;
            if(flag[i]){
                temp+=s[i];
                flag[i]=0;
                dfs(s,len,flag);
                flag[i]=1;
                temp.pop_back();
            }
        }
    }
    vector<string> permutation(string s) {
        int len=(int)s.length();
        sort(s.begin(), s.end());
        vector<int>flag(len,1);
        dfs(s,len,flag);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.permutation("aa");
    return 0;
}
