//
//  main.cpp
//  91. 解码方法
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(len==0||s[0]=='0') return 0;
        if(len==1) return 1;
        vector<int>dp(len,0);
        dp[0]=1;
        if(s[1]=='0'){
            dp[1]=stoi(s.substr(0,2))<=26?1:0;
        }else{
            dp[1]=stoi(s.substr(0,2))<=26?2:1;
        }
        for(int i=2;i<=len-1;i++){
            int cur=s[i]-'0';
            int pre=s[i-1]-'0';
            //判断cur等不等于0
            if(cur==0&&(pre>2||pre==0)){
                return 0;
            }
            if(cur==0){
                dp[i]=dp[i-2];
            }
            if(cur!=0){
                int nums=pre*10+cur;
                bool flag=pre!=0&&nums>=1&&nums<=26;
                dp[i]=(flag?dp[i-2]:0)+dp[i-1];
            }
        }
        return dp[len-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
