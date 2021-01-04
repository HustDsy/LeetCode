//
//  main.cpp
//  605. 种花问题
//
//  Created by dsy on 2021/1/4.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();
        // 每次跳两格
        for(int i=0;i<len;i+=2){
            if(flowerbed[i]==0){
                if(i==len-1||flowerbed[i+1]==0){
                    n--;
                }else{
                    i++;
                }
            }
        }
        return n<=0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
