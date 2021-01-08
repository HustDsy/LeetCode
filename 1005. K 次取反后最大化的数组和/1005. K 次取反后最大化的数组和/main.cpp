//
//  main.cpp
//  1005. K 次取反后最大化的数组和
//
//  Created by dsy on 2021/1/8.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i=0;
        for(i=0;i<A.size()&&A[i]<0&&K>0;i++){
            A[i]*=-1;
            K--;
        }
        sort(A.begin(), A.end());
        while(K){
            A[0]=-A[0];
            K--;
        }
        int ans=accumulate(A.begin(), A.end(),0);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

