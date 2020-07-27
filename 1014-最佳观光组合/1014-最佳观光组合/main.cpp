//
//  main.cpp
//  1014-最佳观光组合
//
//  Created by 董深育 on 2020/7/27.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int len=(int)A.size();
        int max=0;
        int mx=A[0]+0;
        for(int i=1;i<len;i++){
            max=max>mx+A[i]-i?max:mx+A[i]-i;
            mx=mx>A[i]+i?mx:A[i]+i;
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
