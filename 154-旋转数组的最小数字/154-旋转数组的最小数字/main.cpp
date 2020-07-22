//
//  main.cpp
//  154-旋转数组的最小数字
//
//  Created by 董深育 on 2020/7/22.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //当为左边的时候，需要比较数组是否单调递增
    //其次当mid=left的时候，这个时候区间一般只剩下两个元素了
    int minArray(vector<int>& numbers) {
        int len=(int)numbers.size();
        int left=0;
        int right=len-1;
        while(left<right){
            int  mid=left+((right-left)/2);
            if(numbers[mid]==numbers[left]){
                if(mid==left){
                    return numbers[left]<numbers[right]?numbers[left]:numbers[right];
                }else{
                    left++;
                }
            }
            //当左边是有序的
            else if(numbers[mid]>numbers[left]){
                //说明左右都有序
                if(numbers[mid]<=numbers[right]){
                    return numbers[left];
                }else{
                    left=mid+1;
                }
            }
            else if(numbers[mid]<numbers[left]){//右边有序的话 说明目标点 在目标右边
                right=mid;
            }
        }
        return numbers[left];
    }
    //和最右边的比,这时候就不用考虑mid=left时候的特殊情况了
    int minArray_right(vector<int>& numbers) {
        int left=0;
        int right=(int)numbers.size()-1;
        while(left<right){
            int mid=left+((right-left)>>1);
            if(numbers[mid]>numbers[right]){
                left=mid+1;
            }else if(numbers[mid]<numbers[right]){
                right=mid;
            }else if(numbers[mid]==numbers[right]){
                right--;
            }
        }
        return numbers[left];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> numbers={};
    int mun=s.minArray(numbers);
    return 0;
}
