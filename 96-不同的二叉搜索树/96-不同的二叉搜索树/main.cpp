//
//  main.cpp
//  96-不同的二叉搜索树
//
//  Created by 董深育 on 2020/7/15.
//  Copyright © 2020 董深育. All rights reserved.
//


#include <iostream>
using namespace std;

class Solution {
public:
    /*
     int numTrees(int n) {
            if(n==1||n==0){
                return n;
            }
            int num=0;
            for(int i=1;i<=n-2;i++){
                num=num+numTrees(i)*numTrees(n-i-1);
            }
            num=num+2*numTrees(n-1);
            return num;
          
        }
     */
    //记忆化递归
    int*nums;
    int dfs(int n){
        if(nums[n]>0){
            return nums[n];
        }
        if(n==1||n==0){
            nums[n]=1;
            return 1;
        }

        for(int i=1;i<=n-2;i++){
            nums[n]=nums[n]+dfs(i)*dfs(n-i-1);
        }
        nums[n]=nums[n]+2*dfs(n-1);
        return nums[n];
    }
    int numTrees(int n) {
        nums=new int[n+1];
        for(int i=0;i<n+1;i++){
            nums[i]=0;
        }
        return dfs(n);
      
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    int ret=s.numTrees(2);
    cout<<ret;
    return 0;
}
