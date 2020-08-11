//
//  main.cpp
//  120-三角形最小路径和
//
//  Created by 董深育 on 2020/7/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<int>>triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    int ret=s.minimumTotal(triangle);
    return 0;
}
