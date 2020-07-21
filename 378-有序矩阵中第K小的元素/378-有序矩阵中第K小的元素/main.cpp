//
//  main.cpp
//  378-有序矩阵中第K小的元素
//
//  Created by 董深育 on 2020/7/21.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //找出矩阵比mid小的数字
    bool coutNum(vector<vector<int>>& matrix, int k,int mid,int n){
        int i=n-1;
        int j=0;
        int num=0;
        while(i>=0&&j<=n-1){
            if(matrix[i][j]<=mid){
                num+=i+1;
                j++;
            }else{
                i--;
            }
        }
        return num>=k;
    }
    //这里主要就是在意这个left是不是在矩阵中，本题中可就拿13，14作比较。14满足，小于他的数有8个，这时候
    //mid为14，left为13，right为15
    //这时候他在执行一次循环，right变为了14，下一次mid为13 因此结果就是13
    //假设矩阵中的数字为x，那么count(x)=k,现在有mid，count(mid)>=k,那么肯定在矩阵中存在一个数x使得
    //x<mid,且count（x）=count(mid)=k,所以当count（mid）>=k的时候，right=mid；只有当count（mid）
    //小于k的时候 left=mid+1.
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int len=(int)matrix.size();
        int left=matrix[0][0];
        int right=matrix[len-1][len-1];
        while(left<right){
            int mid=left+((right-left)>>2);
            if(coutNum(matrix,k,mid,len)){
                //说明mid太大了
                right=mid;
            }else{
                //说明mid太小了 逐渐逼近
                left=mid+1;
            }
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
