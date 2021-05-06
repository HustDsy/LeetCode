//
//  main.cpp
//  554. 砖墙
//
//  Created by dsy on 2021/5/6.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        unordered_map<int,int>total;
        int maxgap=0;
        for(vector<int>w:wall){
            int sum=0;
            for(int i=0;i<w.size()-1;i++){
                int cur=w[i];
                sum+=cur;
                total[sum]++;
                maxgap=max(total[sum],maxgap);
            }
        }
        return wall.size()-maxgap;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
