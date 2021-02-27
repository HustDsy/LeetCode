//
//  main.cpp
//  561. 数组拆分 I
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
