//
//  main.cpp
//  659. 分割数组为连续子序列
//
//  Created by dsy on 2020/12/4.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
        for (auto& x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>,greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLength = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLength + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>,greater<int>> queue = it->second;
            if (queue.top() < 3) {
                return false;
            }
        }
        return true;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
