//
//  main.cpp
//  1725. 可以形成最大正方形的矩形数目
//
//  Created by dsy on 2021/1/22.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans=0;
        int k=-1;
        for(auto&r:rectangles){
            int cur=min(r[0],r[1]);
            if(k==cur){
                ans++;
            }else if(k>cur){
                continue;
            }else{
                k=cur;
                ans=1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
