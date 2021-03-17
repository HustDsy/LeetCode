//
//  main.cpp
//  剑指 Offer 53 - II. 0～n-1中缺失的数字
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int j=nums.size();
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==mid){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
