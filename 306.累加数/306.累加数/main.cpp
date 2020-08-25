//
//  main.cpp
//  306.累加数
//
//  Created by 董深育 on 2020/8/24.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    //当前剩下的string 以及是否可以三个相加
    bool dfs(vector<long double>isAble,string s){
        int n=static_cast<int>(isAble.size());
        if(n>=3&&isAble[n-1]!=isAble[n-2]+isAble[n-3]){
            return false;
        }
        if(n>=3&&s.length()==0){
            return true;
        }
        for(int i=0;i<s.length();i++){
            string cur=s.substr(0,i+1);
            if(cur[0]=='0'&&cur.size()!=1){
                continue;
            }
            isAble.emplace_back(stold(cur));
            if(dfs(isAble,s.substr(i+1))) return true;
            isAble.pop_back();
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        vector<long double>ret;
        return dfs(ret,num);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
