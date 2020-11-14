//
//  main.cpp
//  1122. 数组的相对排序
//
//  Created by 董深育 on 2020/11/14.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>dp1(1001,0);
        int arr1_len=(int)arr1.size();
        int arr2_len=(int)arr2.size();
        for(int i=0;i<arr1_len;i++){
            dp1[arr1[i]]+=1;
        }
        vector<int>dp2(1001,0);
        for(int i=0;i<arr2_len;i++){
            dp2[arr2[i]]=1;
        }
        vector<int>ans;
        for(int i=0;i<arr2_len;i++){
            for(int j=0;j<dp1[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
        }
        for(int i=0;i<arr1_len;i++){
            if(!dp2[arr1[i]]){
                ans.push_back(arr1[i]);
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
