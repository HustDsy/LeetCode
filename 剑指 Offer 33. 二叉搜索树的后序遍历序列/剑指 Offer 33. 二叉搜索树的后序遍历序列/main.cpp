//
//  main.cpp
//  剑指 Offer 33. 二叉搜索树的后序遍历序列
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //i表示这个树的起点 ，j表示终点 其中j肯定为根节点
    bool dfs(vector<int>& postorder,int i,int j){
        if(i>j) return true;
        //在i，j-1中寻找一个数 是的(i,l)小于j (l+1,j-1)大于j
        int num=postorder[j];
        int k=i;
         while(postorder[k]<num){
            k++;
        }
        int l=k-1;
        //接下来判断k-j-1是不是都大于num
        while(k<=j-1){
            if(postorder[k]<num){
                return false;
            }
            k++;
        }
        return dfs(postorder,i,l)&&dfs(postorder,l+1,j-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        int s=postorder.size();
        return dfs(postorder,0,s-1);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
