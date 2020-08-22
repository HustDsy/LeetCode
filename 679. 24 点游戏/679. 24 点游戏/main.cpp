//
//  main.cpp
//  679. 24 点游戏
//
//  Created by 董深育 on 2020/8/22.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    bool judge(vector<double>&list){
        if(list.size()==0){
            return false;
        }
        if(list.size()==1){
            return fabs(list[0]-24)<1e-6;
        }
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                //选出i，j
                if(j!=i){
                    vector<double>kk;
                    //任意选出两个数字
                    for(int k=0;k<list.size();k++){
                        if(k!=i&&k!=j){
                            kk.push_back(list[k]);
                        }
                    }
                    //对选出来的i，j进行+-乘除法
                    for(int k=0;k<=3;k++){
                        //加法乘法满足交换律
                        if((k==0||k==2)&&i>j){
                            continue;
                        }
                        //加法
                        if(k==0){
                            kk.push_back(list[i]+list[j]);
                        }
                        //剪法
                        if(k==1){
                            kk.push_back(list[i]-list[j]);
                        }
                        //乘法
                        if(k==2){
                            kk.push_back(list[i]*list[j]);
                        }
                        //除法
                        if(k==3){
                            if(fabs(list[j])<(1e-6)){
                                continue;
                            }else{
                                kk.push_back(list[i]/list[j]);
                            }
                        }
                        if(judge(kk)){
                            return true;
                        }
                        kk.pop_back();
                    }
                 
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double>list(4,0);
        list[0]=(double)nums[0];
        list[1]=(double)nums[1];
        list[2]=(double)nums[2];
        list[3]=(double)nums[3];
        return judge(list);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
