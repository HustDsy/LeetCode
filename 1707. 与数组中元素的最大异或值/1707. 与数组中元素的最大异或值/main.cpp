//
//  main.cpp
//  1707. 与数组中元素的最大异或值
//
//  Created by dsy on 2021/5/26.
//

#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

class Trie {
public:
    const int L = 30;

    Trie* children[2] = {};
    int min = INT_MAX;

    void insert(int val) {
        Trie* node = this;
        node->min = std::min(node->min, val);
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->min = std::min(node->min, val);
        }
    }

    int getMaxXorWithLimit(int val, int limit) {
        Trie* node = this;
        if (node->min > limit) {
            return -1;
        }
        int ans = 0;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr && node->children[bit ^ 1]->min <= limit) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        Trie* t = new Trie();
        for (int val : nums) {
            t->insert(val);
        }
        int numQ = queries.size();
        vector<int> ans(numQ);
        for (int i = 0; i < numQ; ++i) {
            ans[i] = t->getMaxXorWithLimit(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/solution/yu-shu-zu-zhong-yuan-su-de-zui-da-yi-huo-7erc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, World!\n";
    return 0;
}
