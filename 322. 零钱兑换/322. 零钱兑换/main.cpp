//
//  main.cpp
//  322. 零钱兑换
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len=coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<len;j++){
                int cur=coins[j];
                if(cur==i){
                    dp[i]=1;
                }else if(i>cur){
                    dp[i]=min(dp[i],dp[i-cur]+1);
                }else{
                    ;
                }
            }
        }
        return dp[amount]>=amount+1?-1:dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
