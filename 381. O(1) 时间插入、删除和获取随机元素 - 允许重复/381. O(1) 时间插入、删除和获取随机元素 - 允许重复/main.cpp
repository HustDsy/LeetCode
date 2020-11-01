//
//  main.cpp
//  381. O(1) 时间插入、删除和获取随机元素 - 允许重复
//
//  Created by 董深育 on 2020/11/1.
//

#include <iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using  namespace std;

//为了查找时间为o(1)，引入一个map，int存的是val，set存的是位置
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        //获取val的索引
        int i = *(idx[val].begin());
        //将i赋值为back
        nums[i] = nums.back();
        //移除这个索引
        idx[val].erase(i);
        //移除最后这个值的索引
        idx[nums[i]].erase(nums.size() - 1);
        //如果i不是最后一个数
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        //idx[val]被删完了的话移除
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        //删除这个值
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
