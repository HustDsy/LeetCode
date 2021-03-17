//
//  main.cpp
//  303. 区域和检索 - 数组不可变
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
using namespace std;



class NumArray {
public:
    vector<int>sum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        sum.resize(n+1);
        for(int i=0;i<n;i++){
            sum[i+1]=sum[i]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
