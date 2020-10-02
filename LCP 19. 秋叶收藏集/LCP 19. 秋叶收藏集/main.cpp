//
//  main.cpp
//  LCP 19. 秋叶收藏集
//
//  Created by 董深育 on 2020/10/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //红黄红
    //状态为0 表示第一部分为红色
    //状态为1 表示第二部分为黄色
    //状态为2 表示第三部分为红色
    int minimumOperations(string leaves) {
        int len=(int)leaves.length();
        //dp[i][state] 表示0-i的叶子编程当前状态所需的最小的值
        vector<vector<int>>dp(len,vector<int>(3,0));
        //dp[0][0] dp[0][0]肯定得为红色，因为这是第一部分
        dp[0][0]=(leaves[0]=='y');
        dp[0][1]=dp[0][2]=dp[1][2]=INT_MAX;
        for(int i=1;i<len;i++){
            int isRed=(leaves[i]=='r');
            int isYellow=(leaves[i]=='y');
            dp[i][0]=dp[i-1][0]+isYellow;
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+isRed;
            if(i>=2){
                dp[i][2]=min(dp[i-1][1],dp[i-1][2])+isYellow;
            }
        }
        return dp[len-1][2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
