//
//  main.cpp
//  690. 员工的重要性
//
//  Created by dsy on 2021/5/6.
//

#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int>idToindex;
        int cur=-1;
        for(int i=0;i<employees.size();i++){
            cur=employees[i]->id;
            idToindex[cur]=i;
        }
        int sum=0;
        int curindex=-1;
        vector<int>subordinates{};
        queue<int>indexs;
        indexs.push(id);
        while(!indexs.empty()){
            int size=(int)indexs.size();
            while(size--){
                curindex=indexs.front();
                indexs.pop();
                sum+=employees[idToindex[curindex]]->importance;
                subordinates=employees[idToindex[curindex]]->subordinates;
                for(int index:subordinates){
                    indexs.push(index);
                }
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
