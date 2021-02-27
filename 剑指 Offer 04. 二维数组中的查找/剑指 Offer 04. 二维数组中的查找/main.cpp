//
//  main.cpp
//  剑指 Offer 04. 二维数组中的查找
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0) return false;
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                j--;
            }else{
                i++;
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
