//
//  main.cpp
//  118. 杨辉三角
//
//  Created by dsy on 2020/12/7.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0) return {};
        if(numRows==1) return {{1}};
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp(i+1,1);
            if(i==0||i==1){
                ans.push_back(temp);
                continue;
            }
            vector<int>back=ans.back();
            for(int j=1;j<i;j++){
                temp[j]=back[j-1]+back[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
