//
//  main.cpp
//  131. 分割回文串
//
//  Created by 董深育 on 2020/8/27.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>>ret;
    void dfs(string s,int pre,vector<string>trace){
        string temp;
        if(pre>=s.size()){
            ret.emplace_back(trace);
            return;
        }
        for(int i=pre;i<s.size();i++){
            bool flag=true;
            temp=s.substr(pre,i-pre+1);
            int wide=(int)temp.size();
            for(int j=0;j<wide;j++){        //判断是否为回文
                if(temp[j]!=temp[wide-1-j]){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                continue;
            }
            trace.push_back(temp);
            dfs(s,i+1,trace);
            trace.pop_back();
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        if(s.length()==0){
            return {};
        }
        dfs(s,0,path);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
