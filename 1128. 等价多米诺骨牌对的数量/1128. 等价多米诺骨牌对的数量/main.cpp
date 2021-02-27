//
//  main.cpp
//  1128. 等价多米诺骨牌对的数量
//
//  Created by dsy on 2021/1/26.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
         vector<int> num(100);
         int ret = 0;
         for (auto& it : dominoes) {
             int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
             ret += num[val];
             num[val]++;
         }
         return ret;
     }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
