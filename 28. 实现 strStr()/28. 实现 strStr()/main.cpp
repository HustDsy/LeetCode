//
//  main.cpp
//  28. 实现 strStr()
//
//  Created by 董深育 on 2020/9/22.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //KMP算法求解
    int strStr(string haystack, string needle) {
        int lenA=(int)haystack.length();
        int lenB=(int)needle.length();
        if(lenB==0){
            return 0;
        }
        //求解next数组
        vector<int>next(lenB,0);
        int i=1;
        int now=next[i-1];
        while(i<lenB){
            if(needle[i]==needle[now]){
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
          while(si<lenA){
              if(haystack[si]==needle[sj]){
                  si++;
                  sj++;
              }else if(sj!=0){
                  sj=next[sj-1];
              }else{
                  si++;
              }
              if(sj==lenB){
                  return si-lenB;
              }
          }
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
