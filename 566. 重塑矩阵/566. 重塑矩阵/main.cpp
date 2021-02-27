//
//  main.cpp
//  566. 重塑矩阵
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int a=nums.size();
        int b=nums[0].size();
        if(a*b!=r*c){
            return nums;
        }
        vector<vector<int>>res(r,vector<int>(c,0));
        int cur=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cur=i*c+j;
                res[i][j]=nums[cur/a][cur%a];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
