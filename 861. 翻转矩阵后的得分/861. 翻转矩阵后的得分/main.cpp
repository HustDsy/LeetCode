//
//  main.cpp
//  861. 翻转矩阵后的得分
//
//  Created by dsy on 2020/12/7.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int ans=0;
        int row=(int)A.size();
        int col=(int)A[0].size();
        //第一列全为1，行变化
        for(int i=0;i<row;i++){
            if(A[i][0]!=1){
                //翻转这一行
                for(int j=1;j<col;j++){
                    A[i][j]=!A[i][j];
                }
            }
        }
        ans=pow(2, col-1)*row;
        //列变化，看看这一列的1多还是0多
        for(int i=1;i<col;i++){
            int cnt=0;
            for(int j=0;j<row;j++){
                if(A[j][i]==1){
                    cnt++;
                }
                cnt=(row-cnt)>cnt?row-cnt:cnt;
                ans+=pow(2,col-1-i)*cnt;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
