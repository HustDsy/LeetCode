//
//  main.cpp
//  剑指 Offer 45. 把数组排成最小的数
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>s;
        for(int n:nums){
            s.emplace_back(to_string(n));
        }
        sort(s.begin(),s.end(),[](string i,string j)->bool{
            return i+j<j+i;
        });
        string ans;
        for(string&t:s){
            ans.append(t);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
