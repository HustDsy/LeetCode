//
//  main.cpp
//  976. 三角形的最大周长
//
//  Created by dsy on 2020/12/1.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int size=static_cast<int>(A.size());
        sort(A.begin(), A.end());
        int ans=0;
        int r_1=size-1;
        while(r_1>=2){
            //每次固定最后两个数字
            int r_2=r_1-1;
            int edge1=A[r_1];
            int edge2=A[r_2];
            for(int i=r_2-1;i>=0;i--){
                //判断可不可以组成三角形
                int edge3=A[i];
                ans=edge1+edge2+edge3;
                //满足条件
                if(edge1<(edge2+edge3)&&edge1>(edge2-edge3)){
                    return ans;
                }
                //说明无法凑成三角形了
                if(edge1>=(edge2+edge3)){
                    break;
                }
            }
            r_1--;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
