//
//  main.cpp
//  189-旋转数组
//
//  Created by 董深育 on 2020/7/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //挨个挨个的移动，超出时间限制
    /*
    void rotate(vector<int>& nums, int k) {
        int len=(int)nums.size();
        for(int i=0;i<k;i++){
            //记录此时要移动的数字
            int target=nums[len-1];
            //需要移动len-1次
            for(int i=len-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=target;
        }
        
    }
     */
    //使用另一个数组
    //这个可以通过
    /*
    void rotate(vector<int>& nums, int k) {
        vector<int>temp=nums;
        int len=(int)nums.size();
        //防止k比len长或者端
        //官方题解更加优秀
        //a[(i + k) % nums.length] = nums[i];
        k=k%len;
        for(int i=0;i<len;i++){
            if(i<k-1){
                nums[i]=temp[i+k+1];
            }else{
                nums[i]=temp[i-k];
            }
        }
    }
     */
    //循环替代，注意for循环条件 很关键
    /*
    void rotate(vector<int>& nums, int k) {
        int len=(int)nums.size();
        k=k%len;//k过大的话就相当于在原位
        int count=0;//记录换位置的次数
        for(int i=0;count<len;i++){
            //记录此时需要换位置的同学
            int current=i;
            int pre=nums[current];
            do{
                //记录被更替的同学
                int next=(current+k)%len;
                //将该同学记录下来
                int temp=nums[next];
                //将换位置的同学换上去
                nums[next]=pre;
                //现在
                pre=temp;
                current=next;
                count++;
            }while(current!=i);
        }
    }*/
    //翻转算法
    //这里要加&，不然的话nums没改变
    void reserse(vector<int>&nums,int begin,int end){
        while(begin<end){
            int temp=nums[begin];
            nums[begin]=nums[end];
            nums[end]=temp;
            begin++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
      //先全部翻转
        int len=(int)nums.size();
        k=k%len;
        reserse(nums, 0, len-1);
        //翻转前k个数字
        reserse(nums,0, k-1);
        //翻转剩下来的数字
        reserse(nums, k, len-1);
        
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
