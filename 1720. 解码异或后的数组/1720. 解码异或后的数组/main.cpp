//
//  main.cpp
//  1720. 解码异或后的数组
//
//  Created by dsy on 2021/5/6.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>arr;
        arr.emplace_back(first);
        for(int item:encoded){
            arr.emplace_back(arr.back()^item);
        }
        return arr;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
