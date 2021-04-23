//
//  main.cpp
//  764. 最大加号标志
//
//  Created by dsy on 2021/4/21.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, N));//初始化所有点都为N
        for (auto &mine : mines){//去除黑名单
            grid[mine[0]][mine[1]] = 0;
        }
        for (int k = 0; k < N; ++k){//k代表第k行，第k列
            int leftOne = 0, rightOne = 0, upOne = 0, downOne = 0;//分别代表上下左右四个方向连续的连续非0的个数
            for (int i = 0, j = N - 1; i < N; ++i, --j){
                //第k行的左边扫描
                leftOne = (grid[k][i] == 0 ? 0 : leftOne + 1);
                grid[k][i] = min(grid[k][i], leftOne);
                //第k行的右边扫描
                rightOne = (grid[k][j] == 0 ? 0 : rightOne + 1);
                grid[k][j] = min(grid[k][j], rightOne);
                //第k列的上边扫描
                upOne = (grid[i][k] == 0 ? 0 : upOne + 1);
                grid[i][k] = min(grid[i][k], upOne);
                //第k列的下边扫描
                downOne = (grid[j][k] == 0 ? 0 : downOne + 1);
                grid[j][k] = min(grid[j][k], downOne);
            }
        }
        //最后寻找最大值
        int maxRes = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                maxRes = max(maxRes, grid[i][j]);
            }
        }
        return maxRes;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > mines={{3,0},{3,3}};
    s.orderOfLargestPlusSign(5, mines);
    return 0;
}
