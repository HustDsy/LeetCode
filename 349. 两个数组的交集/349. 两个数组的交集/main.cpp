//
//  main.cpp
//  349. 两个数组的交集
//
//  Created by 董深育 on 2020/11/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0){
                  return {};
              }
        //排序
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //双指针排序
        int i=0;
        int j=0;
        int len1=static_cast<int>(nums1.size());
        int len2=static_cast<int>(nums2.size());
        vector<int>ans;
        while(i<len1||j<len2){
            int data1=i>=len1?nums1[len1-1]:nums1[i];
            int data2=j>=len2?nums2[len2-1]:nums2[j];
            if(data1==data2){
                i++;
                j++;
                if(!ans.empty()&&data1==ans.back()){
                    continue;
                }
                ans.push_back(data1);
            }else if(data1>data2){
                j++;
                if(j>=len2){
                    break;
                }
            }else if(data1<data2){
                i++;
                if(i>=len1){
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
