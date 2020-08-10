//
//  main.cpp
//  784. 字母大小写全排列
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;



class Solution {
public:
    vector<string>ret;
    string ss;
    void dfs(vector<int>&nums,int begin,vector<int>trace,string s){
        //处理trace
        s=ss;
        if(trace.empty()){
            ret.push_back(s);
        }else{
            for(int i=0;i<trace.size();i++){
                //小写变成大写
                if(s[trace[i]]>='a'&&s[trace[i]]<='z'){
                    s[trace[i]]=s[trace[i]]-32;
                }else if(s[trace[i]]>='A'&&s[trace[i]]<='Z'){            //大写变小写
                    s[trace[i]]=s[trace[i]]+32;
                }
            }
            ret.push_back(s);
        }
        for(int i=begin;i<nums.size();i++){
            trace.push_back(nums[i]);
            dfs(nums,i+1,trace,s);
            trace.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        //记录字母出现的位置
        vector<int>nums;
        this->ss=S;
        int len=(int)S.length();
        for(int i=0;i<len;i++){
            if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z')){
                nums.push_back(i);
            }
        }
        if(nums.size()==0){
            ret.push_back(S);
            return ret;
        }
        vector<int>trace;
        dfs(nums,0,trace,S);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.letterCasePermutation("C");
    return 0;
}
