//
//  main.cpp
//  406. 根据身高重建队列
//
//  Created by 董深育 on 2020/11/16.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>&u,const vector<int>&v){
            return u[0] > v[0] || (u[0] == v[0] && u[1] <v[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
