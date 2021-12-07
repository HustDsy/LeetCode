#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int m;
    int n;
    int val;
    int color;
    vector<vector<int>> flag;
    vector<vector<int>> visited;
    // 将位color的位置 全部置为value
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != val || visited[x][y]) {
            return;
        }
        visited[x][y] = 1;
        //判断是不是边界， 上下左右总得有一个不是color，是边界的话，就得染色
        if (x == 0 || y == 0 || x == m - 1 || y == n - 1 || flag[x - 1][y] ||
            flag[x + 1][y] || flag[x][y - 1] || flag[x][y + 1]) {
            grid[x][y] = color;
        }
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        m = grid.size();
        n = grid[0].size();
        this->color = color;
        val = grid[row][col];
        flag = vector<vector<int>>(m, vector<int>(n, 1));
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == val) {
                    flag[i][j] = 0;
                }
            }
        }
        dfs(grid, row, col);
        return grid;
    }
};