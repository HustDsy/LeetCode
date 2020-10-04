//
//  main.cpp
//  1291. 顺次数
//
//  Created by 董深育 on 2020/10/4.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
 
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ret;
        string target="123456789";

        //判断low是几位数
        int start=log10(low)+1;
        int end=log10(high)+1;
        //指针长度
        for(int len=start;len<=end;len++){
            int i=0;
            while(i<=9-len){
                int num=atoi(target.substr(i,len).c_str());
                if(num>=low&&num<=high){
                    ret.push_back(num);
                }
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
