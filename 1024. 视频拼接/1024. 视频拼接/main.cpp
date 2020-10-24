//
//  main.cpp
//  1024. 视频拼接
//
//  Created by 董深育 on 2020/10/24.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (auto& it : clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
