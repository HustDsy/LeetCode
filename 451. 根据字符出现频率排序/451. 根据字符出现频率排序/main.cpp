//
//  main.cpp
//  451. 根据字符出现频率排序
//
//  Created by dsy on 2021/3/24.
//

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        int maxCount(0);
        for (char c: s)
            maxCount = max(maxCount, ++map[c]);

        vector<vector<int>> buckets(maxCount + 1);
        for (auto i(map.begin()); i != map.end(); i++)
            buckets[i->second].push_back(i->first);

        string ans;
        //有maxCount个频次桶
        for (int i(maxCount); i >= 1; i--)
            //对频次桶里的元素进行遍历，换言之，这个桶里的元素频次一样
            for (int j(0); j < buckets[i].size(); j++) {
                //把这个字母放到ans中i次，也就是频次次
                for (int z(0); z < i; z++)
                    ans.push_back(buckets[i][j]);
            }
        return ans;
    }
};





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
