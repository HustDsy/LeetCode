//
//  main.cpp
//  11. 盛最多水的容器
//
//  Created by 董深育 on 2020/9/22.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //双指针法
    //保留高度较高的那一条边
    int maxArea(vector<int>& height) {
        int i=0;
        int j=(int)height.size()-1;
        if(j<0){
            return 0;
        }
        int ret=0;
        while(i<j){
            ret=max(ret,(j-i)*min(height[i],height[j]));
            if(height[i]>height[j]){
                j--;
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
