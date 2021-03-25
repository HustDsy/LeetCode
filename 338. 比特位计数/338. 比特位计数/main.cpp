//
//  main.cpp
//  338. 比特位计数
//
//  Created by dsy on 2021/3/22.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i&(i-1)]+1;
        }
        return dp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
