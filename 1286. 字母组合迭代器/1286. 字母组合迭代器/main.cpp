//
//  main.cpp
//  1286. 字母组合迭代器
//
//  Created by 董深育 on 2020/9/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class CombinationIterator {
public:
    int index;//初始化为0
    vector<string>ss;//所有的string数组
    void dfs(string characters,int combinationLength,string kk,int begin){
        if(kk.length()==combinationLength){
            ss.emplace_back(kk);
            return;
        }
        for(int i=begin;i<characters.length();i++){
            if(i>begin&&characters[i-1]==characters[i]) continue;
            dfs(characters,combinationLength,kk+characters[i],i+1);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        index=0;
        sort(characters.begin(), characters.end());
        vector<int>flag(characters.length(),0);
        dfs(characters,combinationLength,"",0);
    }
    
    string next() {
        string ret=ss[index];
        index+=1;
        return ret;
    }
    
    bool hasNext() {
        return !(index>=(int)ss.size());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
