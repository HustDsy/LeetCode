//
//  main.cpp
//  867. 转置矩阵
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>>B(A);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                int temp=B[j][i];
                B[j][i]=temp;
                B[i][j]=temp;
            }
        }
        return B;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
