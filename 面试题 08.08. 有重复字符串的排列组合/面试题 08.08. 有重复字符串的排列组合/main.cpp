//
//  main.cpp
//  面试题 08.08. 有重复字符串的排列组合
//
//  Created by 董深育 on 2020/8/22.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string>ret;
    void getString(int num,string kk,int size,string s,vector<int>flag){
        if(num==size){
            ret.push_back(kk);
        }
        for(int i=0;i<size;i++){
            //没有被选择的话
            if(flag[i]==0){
                if(i>0&&s[i]==s[i-1]&&flag[i-1]==1){
                    continue;
                }
                kk+=s[i];
                flag[i]=1;
                getString(num+1, kk, size, s,flag);
                kk.pop_back();
                flag[i]=0;
            }
           
        }
    }
    vector<string> permutation(string S) {
        sort(S.begin(),S.end());
        int size=static_cast<int>(S.length());
        vector<int>flag(size,0);
        getString(0, "", size,S,flag);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.permutation("qqz");
    return 0;
}
