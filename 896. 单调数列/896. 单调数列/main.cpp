//
//  main.cpp
//  896. 单调数列
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        bool p=true;
        bool q=true;
        int l=A.size();
        if(l==0||l==1) return true;
        for(int i=1;i<l;i++){
            if(A[i]<A[i-1]){
                p=false;
            }
            if(A[i]>A[i-1]){
                q=false;
            }
        }
        return p||q;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
