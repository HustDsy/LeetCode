//
//  main.cpp
//  121-买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int len=(int)prices.size();
        if(len==0){
            return 0;
        }
        int maxRet=0;
        int minNum=prices[0];
        for(int i=1;i<len;i++){
            maxRet=max(maxRet,prices[i]-minNum);
            minNum=min(minNum,prices[i]);
        }
        return maxRet;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
