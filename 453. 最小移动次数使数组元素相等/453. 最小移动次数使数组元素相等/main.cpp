//
//  main.cpp
//  453. 最小移动次数使数组元素相等
//
//  Created by 董深育 on 2020/10/27.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int len=static_cast<int>(nums.size());
        int min=INT_MAX;
        //相当于选一个数字减一，这就意味着我们只需要将每个nums减小到最小数字所需要的次数
        for(int i=0;i<len;i++){
            min=min<nums[i]?min:nums[i];
        }
        for(int i=0;i<len;i++){
            ans=ans+nums[i]-min;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
