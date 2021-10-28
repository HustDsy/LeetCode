//
//  main.cpp
//  240-搜索二维矩阵(2)
//
//  Created by 董深育 on 2020/7/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution{
public:
    //二分法超出时间限制
    /*
    bool binarySearch(vector<int>array,int target){
        int left=0;
        int right=array.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==array[mid]){
                return true;
            }else if(target>array[mid]){
                left=mid+1;
                
            }else if(target<array[mid]){
                right=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(binarySearch(matrix[i], target)){
                return true;
            }
        }
        return false;
        
    }
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        //行数
        int row=matrix.size();
        //列数
        int col=matrix[0].size();
        //选择出发点为左下角的点
        int i=row-1;
        int j=0;
        while(i>=0&&j<=col-1){
            int mid=matrix[i][j];
            if(mid==target){
                return true;
            }else if(mid>target){
                i--;
            }else if(mid<target){
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
