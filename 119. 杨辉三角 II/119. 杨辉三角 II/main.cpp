//
//  main.cpp
//  119. 杨辉三角 II
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre, cur;
        for(int i=0;i<=rowIndex;i++){
            cur.resize(i+1);
            cur[0]=cur[i]=1;
            for(int j=1;j<i;j++){
                cur[j]=pre[j-1]+pre[j];
            }
            pre=cur;
        }
        return pre;
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    s.getRow(3);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
