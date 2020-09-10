//
//  main.cpp
//  31. 下一个排列
//
//  Created by 董深育 on 2020/9/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //先从右往左，找到第一个不是顺序的数，比如  1 2 9  7 8  6 5  4 3
    //找到这个数是7
    //再从8-3当中 找到第一个比他大的数，交换 即可  1 2 9 8 7 6 5 4 3
    //翻转（i+1,len） 1 2 9 8 3 4 5 6 7
    void nextPermutation(vector<int>& nums) {
        int len=(int)nums.size();
        int i=len-2;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j=len-1;
            while(j>=(i+1)&&nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
            
        }
        vector<int>::iterator it=nums.begin();
        advance(it, i+1);
        reverse(it, nums.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
