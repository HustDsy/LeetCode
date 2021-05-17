//
//  main.cpp
//  1310. 子数组异或查询
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i]^pre[i-1];
        }
        int t=queries.size();
        vector<int>ans(t,0);
        int x,y;
        for(int i=0;i<t;i++){
            x=queries[i][0];
            y=queries[i][1];
            ans[i]=pre[y]^pre[x]^arr[x];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
