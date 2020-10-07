//
//  main.cpp
//  75. 颜色分类
//
//  Created by 董深育 on 2020/10/7.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=(int)nums.size();
        int p=0;
        int q=len-1;
        for(int i=0;i<=q;i++){
            if(nums[i]==0){
                nums[i]=nums[p];
                nums[p]=0;
                p++;
            }
            if(nums[i]==2){
                nums[i]=nums[q];
                nums[q]=2;
                q--;
                --i;
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
