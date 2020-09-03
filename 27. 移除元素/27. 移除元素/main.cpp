//
//  main.cpp
//  27. 移除元素
//
//  Created by 董深育 on 2020/9/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin=0;
        int end=(int)nums.size()-1;
        int vals=0;
        while(begin<=end){
            if(nums[begin]==val){
                swap(nums[begin],nums[end]);
                vals++;
                end--;
            }else{
                begin++;
            }
        }
    return (int)nums.size()-vals;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
