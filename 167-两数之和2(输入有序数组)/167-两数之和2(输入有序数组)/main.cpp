//
//  main.cpp
//  167-两数之和2(输入有序数组)
//
//  Created by 董深育 on 2020/7/20.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=(int)numbers.size();
        int left=0;
        int right=len-1;
        vector<int>ret;
        while(left<right){
            int temp=numbers[left]+numbers[right];
            if(temp==target){
                ret.push_back(left+1);
                ret.push_back(right+1);
                return ret;
            }else if(temp>target){
                right--;
            }else if(temp<target){
                left++;
            }
        }
        return {};
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
