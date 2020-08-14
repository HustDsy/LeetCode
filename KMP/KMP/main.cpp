//
//  main.cpp
//  KMP
//
//  Created by 董深育 on 2020/8/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

//看看s是否在p里面
bool isIn(string p,string s){
    //首先求next数组n
    if(s==""){
        return false;
    }
    int len=(int)s.length();
    vector<int>next(len,0);
    //next为第一个数字的时候就是next就是0，这个代表长度
    next[0]=0;
    int i=1;
    int now=0;
    while(i<=len-1){
        if(s[now]==s[i]){
            now=now+1;
            next[i]=now;
               i+=1;
        }else if(now!=0){
            now=next[now-1];
        }else{
            next[i]=0;
            i+=1;
        }
    }
    //接下来 kmp
    int si=0;
    int sj=0;
    while(si<p.length()){
        if(p[si]==p[sj]){
            si++;
            sj++;
        }else if(sj!=0){
            sj=next[sj-1];
        }else{
            si++;
        }
        if(sj==len){
            return true;
        }
    }
    return false;;
}
int main(int argc, const char * argv[]) {
    cout<<isIn("ababababca", "abababca");
    return 0;
}
