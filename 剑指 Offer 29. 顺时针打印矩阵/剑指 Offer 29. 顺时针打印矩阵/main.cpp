//
//  main.cpp
//  剑指 Offer 29. 顺时针打印矩阵
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int cur=0;
        int nums=0;
        int tnum=m*n;
        while(nums<tnum){
            for(int j=cur;j<=n-cur-1;j++){
                ans.push_back(matrix[cur][j]);
            }
            for(int i=cur+1;i<=m-cur-1;i++){
                ans.push_back(matrix[i][n-cur-1]);
            }
            for(int j=n-cur-2;j>=cur;j--){
                ans.push_back(matrix[m-cur-1][j]);
            }
            for(int i=m-cur-2;i>=cur+1;i--){
                ans.push_back(matrix[i][cur]);
            }
            cur++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
