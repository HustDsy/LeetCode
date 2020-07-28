//
//  main.cpp
//  14-最长公共前缀
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        int len=(int)strs.size();
        if(len==0){
            return "";
        }
        if(len==1){
            return strs[0];
        }
        string pivot=strs[0];
        for(int i=0;i<pivot.length();i++){
            bool flag=true;
            for(int j=1;j<len;j++){
                if(i+1>strs[j].length()||pivot[i]!=strs[j][i]){
                    flag=false;
                    return commonPrefix;
                }
            }
            
            commonPrefix+=pivot[i];
            
        }
        return commonPrefix;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
