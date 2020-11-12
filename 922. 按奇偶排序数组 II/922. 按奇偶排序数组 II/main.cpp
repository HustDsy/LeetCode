//
//  main.cpp
//  922. 按奇偶排序数组 II
//
//  Created by 董深育 on 2020/11/12.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
