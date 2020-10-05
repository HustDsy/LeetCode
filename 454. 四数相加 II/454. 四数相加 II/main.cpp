//
//  main.cpp
//  454. 四数相加 II
//
//  Created by 董深育 on 2020/10/5.
//

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>ret;
        int count=0;
        int len=(int)A.size();
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                ret[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if (ret.find(0 - (C[i]+D[j])) != ret.end()) {
                    count += ret[0 - (C[i]+D[j])];
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
