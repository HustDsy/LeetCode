//
//  main.cpp
//  518. 零钱兑换 II
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int l=coins.size();
        vector<int>dp(amount+1);
        dp[0]=1;
        for(int i=0;i<l;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j]+=dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
