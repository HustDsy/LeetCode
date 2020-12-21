//
//  main.cpp
//  48. 旋转图像
//
//  Created by dsy on 2020/12/19.
//

#include <iostream>
#include<vector>
using namespace std;




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先转置
        int n=static_cast<int>(matrix.size());
        if(n==1) return;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //然后逐列交换
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
