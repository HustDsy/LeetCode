//
//  main.cpp
//  52. N皇后 II
//
//  Created by 董深育 on 2020/10/17.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;


class Solution {
public:
    int ans;
    //K表示现在轮到了第几行，point表示这一行可以选择那些位置
    void dfs(int k,vector<vector<int>>&point,int n){
        if(k==n-1){
            //得到point中为1的数量即可,也就是可以选择的位置
            ans=ans+accumulate(point.begin(), point.end(), 0);
            return;
        }
        for(int i=0;i<n;i++){
            //为0表示后不可选
            if(point[k][i]==0)continue;
            vector<vector<int>>pre=point;
            //为1的话表示选择了这个位置，这样的话 我要更新point，这一列的位置不能选了，并且斜线也不能选了
            //先更新这个一列的点
            for(int j=k;j<n;j++){
                point[j][i]=0;
            }
            //更新斜线,这个时候的点是k，i
            for(int q=k+1;q<n;q++){
                int changenum=q-k;
                if(i-changenum>=0){
                    point[q][i-changenum]=0;
                }
                if(i+changenum<=n-1){
                    point[q][i+changenum]=0;
                }
            }
            dfs(k+1,point,n);
            //更新状态 ,回到上一层的状态
            point=pre;
        }
        
    }
    int totalNQueens(int n) {
        ans=0;
        vector<vector<int>>point(n,vector<int>(n,1));
        dfs(0,point,n);
        return ans;
    }
    //位运算实现,row占用的列,ld横线，rd斜线
    void test(int n,int row,int col,int ld,int rd,int upplim){
         if(row>=n){
             ans++;
             return;
         }
         //可选的位置
         int pos=upplim&~(ld|rd|col);
         while(pos>0){
             //得到最右边的1
             int p=pos&-pos;
             pos=pos&(pos-1);
             test(n,row+1,col|p,(ld|p)<<1,(rd|p)>>1,upplim);
        
         }
     }
    int totalNQueens_(int n) {
           int upplim=(1<<n)-1;
           test(n,0,0,0,0,upplim);
           return ans;
       }
   
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
