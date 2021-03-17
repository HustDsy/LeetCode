//
//  main.cpp
//  879. 盈利计划
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>>dp(n+1,vector<int>(minProfit+1,0));
        int sg=group.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<sg;i++){
            int vg=group[i];//需要用多少人
            int vp=profit[i];
            //j是看多少人
            for(int j=n;j>=vg;j--){
                for(int k=minProfit;k>=0;k--){
                    dp[j][k]+=dp[j-vg][max(k-vp,0)];
                }
            }
            
        }
        return  dp[n][minProfit];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
