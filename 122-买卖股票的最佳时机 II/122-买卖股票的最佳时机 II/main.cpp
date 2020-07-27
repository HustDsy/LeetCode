//
//  main.cpp
//  122-买卖股票的最佳时机 II
//
//  Created by 董深育 on 2020/7/27.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //找出所有的高谷和低谷
    int maxProfit(vector<int>& prices) {
        int ret=0;
        int len=(int)prices.size();
        if(len==0){
            return 0;
        }
        for(int i=0;i<len;i++){
            int high=i+1;
            int highNum=0;
            int lowNum=prices[i];
            while(high<len&&prices[high]>prices[high-1]){
                highNum=prices[high];
                high++;
                i++;
            }
            ret=ret+max(0,highNum-lowNum);
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution s;
    vector<int>temp={7,1,5,3,6,4};
    int ret=s.maxProfit(temp);
    std::cout << "Hello, World!\n";
    return 0;
}
