//
//  main.cpp
//  1283. 使结果不超过阈值的最小除数
//
//  Created by dsy on 2021/1/19.
//

#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

class Solution {
public:
     int smallestDivisor(vector<int>& nums, int threshold) {
        int max=*max_element(nums.begin(), nums.end());
        int left=1;
        int right=max;
        int res=0;
        int l=nums.size();
        while(left<=right){
            int mid=(left+right)/2;
            int t=0;
            for(int i=0;i<l;i++){
                t+=(nums[i] - 1) / mid + 1;
            }
            if(t<=threshold){
                res=mid;
                 right=mid-1;
                
            }else{
              left=mid+1;
            }
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
