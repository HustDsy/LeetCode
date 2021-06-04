//
//  main.cpp
//  523. 连续的子数组和
//
//  Created by dsy on 2021/6/2.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    //主要是同余定理
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<int> sum(n + 1);
        hash[0] = 0;
        for (int i = 1; i <= n; ++i) { // 前缀和下标从1开始
            sum[i] = sum[i - 1] + nums[i - 1];
            hash[sum[i] % k] = i; // 哈希表存储前缀和取模k的值和对应的数组下标
        }
        for (int i = 0; i <= n; ++i) {
            auto target = sum[i] % k;
            if (hash.count(target) && hash[target] - i >= 2) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
