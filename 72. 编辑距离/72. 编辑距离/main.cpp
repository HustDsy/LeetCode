//
//  main.cpp
//  72. 编辑距离
//
//  Created by dsy on 2021/3/12.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        if(!len1&&!len2) return 0;
        if(!len1) return len2;
        if(!len2) return len1;
        int dp[len1+1][len2+1];
        memset(dp,INT_MAX,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=len1;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=len2;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    //第一种是i-1和j-1相等
                    //第二种是dp[i-1][j]删除一个
                    //第三种是dp[i][j-1]删除一个
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }else{
                    //不相等
                     dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
