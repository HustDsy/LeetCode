//
//  main.cpp
//  5-最长回文子串
//
//  Created by 董深育 on 2020/6/11.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return s;
        }
        int num=(int)s.size();//得到string的长度
        int arry[num][num];
        string maxs;//记录最长的回文串
        //最外层循环代表子串长度
        for(int i=0;i<num;i++){
            for(int j=0;j<num ;j++){
                arry[i][j]=1;
            }
        }
        for(int l=0;l<num;l++){
            for(int i=0;i<num-l;i++){
                //长度为一那一定就是回文数字
                int j=i+l;
                if(l==0){
                    arry[i][j]=1;
                }
                //长度为2的话 ，那么数两个数字一样则为回文数
                else if(l==1){
                    if(s[i]==s[j]){
                        arry[i][j]=1;
                    }else{
                        arry[i][j]=0;
                    }
                }else{
                    arry[i][j]=(arry[i+1][j-1]==1)&&(s[i]==s[j]);
                }
                if(arry[i][j]==1&&(l+1)>maxs.size()){
                    maxs=s.substr(i,(j-i+1));
                }
                
            }
        }
        return maxs;
    }
};

int main(int argc, const char * argv[]) {
    string s="abcda";
    Solution ss;
    cout<<ss.longestPalindrome(s)<<endl;
    return 0;
}
