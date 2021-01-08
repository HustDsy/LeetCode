//
//  main.cpp
//  830. 较大分组的位置
//
//  Created by dsy on 2021/1/5.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int len=s.length();
        vector<vector<int>>ans;
        vector<int>temp(2,0);
        int p=0;
        int q=0;
        for(int i=0;i<len-1;i++){
            p=i;
            while(s[i]==s[i+1]){
                q=i+1;
                i++;
            }
            if(q-p+1>=3){
                temp[0]=p;
                temp[1]=q;
                ans.push_back(temp);
            }
            q=0;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
