//
//  main.cpp
//  17. 电话号码的字母组合
//
//  Created by 董深育 on 2020/8/26.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string>ret;
    string getNum(char i){
        if(i=='2'){
            return "abc";
        }
        if(i=='3'){
            return "def";
        }
        if(i=='4'){
            return "ghi";
        }
        if(i=='5'){
            return "jkl";
        }
        if(i=='6'){
            return "mno";
        }
        if(i=='7'){
            return "pqrs";
        }
        if(i=='8'){
            return "tuv";
        }
        if(i=='9'){
            return "wxyz";
        }
        return {};
    }
    //首先把所有数字的组合求出来
    
    void dfs(int len,string kk,string digits,int cur){
        if(len==kk.length()){
            ret.emplace_back(kk);
            cout<<kk<<endl;
            return;
        }
        for(int i=cur;i<len;i++){
            //如果i没被访问的话
     
                string num=getNum(digits[i]);
                for(int j=0;j<num.size();j++){
                    dfs(len,kk+num[j],digits,i+1);
                }
            
            
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int len=static_cast<int>(digits.length());
        if(len==0){
            retunr {};
        }
        string kk="";
        vector<int>flag(len,0);
        dfs(len,kk,digits,0);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
   
    vector<string>tt= s.letterCombinations("23");
    return 0;
}
