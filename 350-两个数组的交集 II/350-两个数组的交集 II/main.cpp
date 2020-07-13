//
//  main.cpp
//  350-两个数组的交集 II
//
//  Created by 董深育 on 2020/7/13.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*
    vector<int>intersect(vector<int>& nums1, vector<int>& nums2) {
        int size2=(int)nums2.size();
        vector<int>ret={};
        for(int i=0;i<size2;i++){
            vector<int>::iterator flag=find(nums1.begin(),nums1.end(),nums2[i]);
            if(flag!=nums1.end()){
                nums1.erase(flag);
                ret.push_back(nums2[i]);
            }
        }
        return ret;

    }*/
    vector<int>intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int size1=(int)nums1.size();
        int size2=(int)nums2.size();
        int i=0,j=0;
        vector<int>ret={};
        while(i<size1&&j<size2){
            if(nums1[i]==nums2[j]){
                ret.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
