//
//  main.cpp
//  718-最长重复子数组
//
//  Created by 董深育 on 2020/7/20.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //时间超级长，勉强通过
    /*
    int findLength(vector<int>& A, vector<int>& B) {
        int ret=0;
        int len1=(int)A.size();
        int len2=(int)B.size();
        if(len1>len2){
            return findLength(B, A);
        }
        for(int i=0;i<len1;i++){
            if(len1-i<=ret){
                return ret;
            }
            //先找到一样的b
            for(int j=0;j<len2;j++){
                int max=0;//记录当前最长字符串
                if(A[i]==B[j]){
                    int a=i;//用来记录A的变化
                    int b=j;//用来记录B的变化
                    while(b<=len2-1&&a<=len1-1){
                        if(A[a]==B[b]){
                            max++;
                            a++;
                            b++;
                        }else{
                            break;
                        }
                    }
                }
                ret=max>ret?max:ret;
            }
          
        }
        return ret;

    }
     */
    /*
    //辅助函数，判断两个数组的对应的交集
    int getMax(vector<int>&A,int i,vector<int>&B,int j,int len){
        int ret=0,max=0;
        for(int k=0;k<len;k++){
            if(A[i+k]==B[j+k]){
                max++;
            }else{
                max=0;
            }
            ret=ret>max?ret:max;
        }
        return ret;
    }
    //滑动窗口
    int findLength(vector<int>& A, vector<int>& B) {
        int ret=0;
        int len1=(int)A.size();
        int len2=(int)B.size();
        //A的长度小于B
        if(len1>len2){
            return findLength(B, A);
        }
        //第一种情况，B和A的比较长度为0~len1-1，B的开头为len2-1
        for(int len=1;len<=len1-1;len++){
            ret=max(ret,getMax(A,0,B,len2-len,len));
        }
        //第二种情况，长度永远为len1
        for(int i=len2-len1+1;i>=0;i--){
            ret=max(ret,getMax(A,0,B,i,len2));
        }
       //第三种情况，B和A比较的长度为len1-1~0,B的开头为0
        for(int len=len1-1;len>=1;len--){
            ret=max(ret,getMax(A,len1-len,B,0,len));
        }
        return ret;
    }
     */
    //动态规划
    int findLength(vector<int>& A, vector<int>& B){
        int len1=(int)A.size();
        int len2=(int)B.size();
        int dp[len1][len2];
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                dp[i][j]=0;
            }
        }
        int ret=0;
        for(int i=len1-1;i<=0;i--){
            for(int j=len2-1;j>=0;j--){
                if(A[i+1]==A[j+1]){
                    dp[i][j]=dp[i+1][j+1]+1;
                }else{
                    dp[i][j]=0;
                }
                ret=max(dp[i][j],ret);
            }
        }
        return ret;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int len = 10;
    int arr[len];
    return 0;
}
