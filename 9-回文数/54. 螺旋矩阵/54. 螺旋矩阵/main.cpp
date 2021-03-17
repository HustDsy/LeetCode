//
//  main.cpp
//  54. 螺旋矩阵
//
//  Created by dsy on 2021/3/15.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int size=0;
        //可以遍历mci
        for(int i=0;i<=m-1;i++){
            //先是最右边
            for(int j=i;j<=n-1-i;j++){
                ans.push_back(matrix[i][j]);
                size++;
            }
            if(size>=m*n) break;
            //往下走
            for(int k=i+1;k<=m-i-1;k++){
                ans.push_back(matrix[k][n-i-1]);
                size++;
            }
            if(size>=m*n) break;
            //往左走
            for(int p=n-i-2;p>=i;p--){
                ans.push_back(matrix[m-i-1][p]);
                size++;
            }
            if(size>=m*n) break;
            //往上走
            for(int q=m-i-2;q>=i+1;q--){
                 ans.push_back(matrix[q][i]);
                 size++;
            }
            if(size>=m*n) break;

        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
