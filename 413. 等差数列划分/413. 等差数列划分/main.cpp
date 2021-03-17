//
//  main.cpp
//  413. 等差数列划分
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 0;
        vector<int>dp(n,0);
        int res=0;
        for(int i=2;i<=n-1;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
                res+=dp[i];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
