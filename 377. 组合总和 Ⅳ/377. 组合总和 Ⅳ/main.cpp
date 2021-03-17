//
//  main.cpp
//  377. 组合总和 Ⅳ
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int t:nums){
                if(t<=i){
                    dp[i]=dp[i]+dp[i-t];
                }
            }
        }
        return dp[target];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
