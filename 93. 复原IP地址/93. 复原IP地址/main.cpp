//
//  main.cpp
//  93. 复原IP地址
//
//  Created by 董深育 on 2020/8/9.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string>ret;
    vector<string>segment;
    void dfs(vector<string>segment,int begin,string s){
        if(segment.size()==4&&begin==s.length()){
            string kk=segment[0]+"."+segment[1]+"."+segment[2]+"."+segment[3];
            ret.push_back(kk);
            return;
        }
        if(segment.size()==4&&begin<s.length()){
            return;
        }
        for(int len=1;len<=3;len++){
            if(begin+len-1>=s.length()){
                return;
            }
            if(len!=1&&s[begin]=='0'){
                return;
            }
            string str=s.substr(begin,len);
            if(len==3&&atoi(str.c_str())>255){
                return;
            }
            segment.push_back(str);                            // 作出选择
            dfs(segment, begin + len,s);                    // 基于这种选择，向下选择
            segment.pop_back();
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(segment,0,s);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
