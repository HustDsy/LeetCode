//
//  main.cpp
//  1047. 删除字符串中的所有相邻重复项
//
//  Created by dsy on 2021/3/22.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        int n=S.length();
        if(n==0) return S;
        string v="";
        for(int i=0;i<n;i++){
            if(v.empty()){
                v.push_back(S[i]);
            }else{
                if(S[i]==v.back()){
                    v.pop_back();
                }else{
                    v.push_back(S[i]);
                }
            }
        }
        return v;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
