//
//  main.cpp
//  88. 合并两个有序数组
//
//  Created by dsy on 2021/3/19.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int cur=m+n-1;
        int i=n-1;
        int j=m-1;
       while(i>=0&&j>=0){
           if(nums1[j]>=nums2[i]){
               nums1[cur--]=nums1[j--];
           }else{
               nums1[cur--]=nums2[i--];
           }
       }
       for(;i>=0;i--){
           nums1[cur--]=nums2[i];
       }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
