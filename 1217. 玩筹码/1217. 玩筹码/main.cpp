//
//  main.cpp
//  1217. 玩筹码
//
//  Created by dsy on 2021/1/19.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int num : position) {
            if ((num & 1) == 0) even++;
            else odd++;
        }
        return min(odd, even);


    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
