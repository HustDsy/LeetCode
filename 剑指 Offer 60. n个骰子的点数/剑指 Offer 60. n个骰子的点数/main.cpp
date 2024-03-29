//
//  main.cpp
//  剑指 Offer 60. n个骰子的点数
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res(n * 6 - n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1, 0)); // 将全部值初始化为 0

        int row = dp.size(), col = dp[0].size();

        for (int n = 1; n <= 6; ++n) {
            // 初始化 dp 数组
            dp[1][n] = 1;
        }

        for (int n = 2; n < row; ++n) {
            for (int s = n; s < col; ++s) {
                // 注意 s 从 n 开始，因为 s 的最小值为 n
                // 比如掷 3 个骰子，s 最小为 3
                for (int k = 1; k <= 6; ++k) {
                    if (s - k > 0) {
                        dp[n][s] += dp[n - 1][s - k];
                    } else {
                        break;
                    }
                }
            }
        }

        double denominator = pow(6.0, n); // 分母

        for (int s = n; s <= 6 * n; ++s) {
            // s 的最小值为 n，在 res 里是第 s - n 位
            res[s - n] = dp[n][s] / denominator;
        }

        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
