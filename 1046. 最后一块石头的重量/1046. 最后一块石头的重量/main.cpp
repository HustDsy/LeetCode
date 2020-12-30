//
//  main.cpp
//  1046. 最后一块石头的重量
//
//  Created by dsy on 2020/12/30.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len=(int)stones.size();
        int p=0;
        int q=0;
        int r=0;
        while(len>1){
            sort(stones.begin(),stones.end());
            p=stones[len-1];
            q=stones[len-2];
            if(p==q){
                stones.erase(stones.begin()+len-1);
                stones.erase(stones.begin()+len-2);
                len=len-2;
            }else{
                stones.erase(stones.begin()+len-1);
                stones.erase(stones.begin()+len-2);
                r=abs(p-q);
                stones.push_back(r);
                len=len-1;
            }
        }
        return len==1?stones[0]:0;
    }
};
 

int main(int argc, const char * argv[]) {
    vector<int>a={2,7,4,1,8,1};
    Solution s;
    s.lastStoneWeight(a);
    return 0;
}
