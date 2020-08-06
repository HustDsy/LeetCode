//
//  main.cpp
//  马拉车算法
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

int getMax(string s){
    //怕越界 主要是有一个ss[i+p[i]]和ss[i-p[i]]这里的比较
    string ss="$#";
    int len=(int)s.length();
    for(int i=0;i<len;i++){
      
        ss+=s[i];
        ss+="#";
    }
    len=(int)ss.length();
    int r=0;//最右端的值
    int mid=0;//中心点
    int maxlen=0;//长度
    vector<int>p(len,0);
    for(int i=1;i<len;i++){
        p[i]=r>i?1:min(p[2*mid-i],r-i);
        while(ss[i+p[i]]==ss[i-p[i]]){
            p[i]++;
        }
        if(r<i+p[i]){
            r=i+p[i];
            mid=i;
        }
        if(maxlen<p[i]){
            maxlen=p[i];
        }
        
    }
    return maxlen-1;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
