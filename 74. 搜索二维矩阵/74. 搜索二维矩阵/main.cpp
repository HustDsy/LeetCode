//
//  main.cpp
//  74. 搜索二维矩阵
//
//  Created by dsy on 2021/3/30.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1;
        int j=0;
        while(i>=0&&j<n){
            int  cur=matrix[i][j];
            if(cur==target){
                return true;
            }else if(cur>target){
                i--;
            }else{
                j++;
            }
        }
        return false;
    }
}; 


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
