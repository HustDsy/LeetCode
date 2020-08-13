//
//  main.cpp
//  快乐数
//
//  Created by 董深育 on 2020/8/13.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        string nn=to_string(n);
        int len=(int)nn.length();
        unordered_map<int,int>map;
        int ret=0;
        while(ret!=1){
            ret=0;
            for(int i=0;i<len;i++){
                ret+=(nn[i]-'0')*(nn[i]-'0');
            }
            nn=to_string(ret);
            len=nn.length();
            if(map.find(ret)!=map.end()){
                return false;
            }else{
                map[ret]=ret;
            }
            if(ret==1){
                return true;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.isHappy(2);
    return 0;
}
