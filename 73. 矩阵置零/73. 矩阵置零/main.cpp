//
//  main.cpp
//  73. 矩阵置零
//
//  Created by dsy on 2021/3/14.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(n==0) return;
        //先处理行
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        matrix[i][k]=matrix[i][k]==0?-INT_MAX:0;
                    }
                    break;
                }
            }
        }
        //再处理列
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-INT_MAX){
                    for(int k=0;k<m;k++){
                        matrix[k][j]=0;
                    }
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
