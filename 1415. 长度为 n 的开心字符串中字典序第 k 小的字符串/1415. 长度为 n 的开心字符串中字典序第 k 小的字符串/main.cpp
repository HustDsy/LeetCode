//
//  main.cpp
//  1415. 长度为 n 的开心字符串中字典序第 k 小的字符串
//
//  Created by 董深育 on 2020/9/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string>happyNums;
    void dfs(int n,int k,vector<char>&characters,string s){
        if(happyNums.size()==k){
                       return;
                   }
        if(s.length()==n){
            happyNums.emplace_back(s);
            return;
        }
        for(int i=0;i<3;i++){
            //这一层不能选择和最后一个数相相同的元素
            if(s.length()!=0&&s.back()==characters[i]) continue;
           
            dfs(n,k,characters,s+characters[i]);
        }
        
    }
    string getHappyString(int n, int k) {
        vector<char>characters={'a','b','c'};
        dfs(n,k,characters,"");
        if(happyNums.size()<k) return "";
        return happyNums.back();
    }
    void print(){
        vector<string>::iterator it=happyNums.begin();
        for(;it<happyNums.end();it++){
            cout<<*it<<endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.getHappyString(3, 9)<<endl;
    s.print();
    return 0;
}
