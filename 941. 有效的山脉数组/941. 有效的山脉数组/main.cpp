//
//  main.cpp
//  941. 有效的山脉数组
//
//  Created by 董深育 on 2020/11/3.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len=static_cast<int>(A.size());
        int top=-1;
        for(int i=0;i<len;i++){
            if(i!=0&&A[i]<A[i-1]){
                top=i-1;
                break;
            }
            if(i!=0&&A[i]==A[i-1]){
                return false;
            }
        }
        if(top==-1||top==0){
            return  false;
        }
        for(int i=top+1;i<len;i++){
            if(A[i]>=A[i-1]) return false;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>A={9,8,7,6,5,4,3,2,1,0};
    s.validMountainArray(A);
    return 0;
}
