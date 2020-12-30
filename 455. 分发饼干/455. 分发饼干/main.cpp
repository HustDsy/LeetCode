//
//  main.cpp
//  455. 分发饼干
//
//  Created by dsy on 2020/12/25.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int glen=(int)g.size();
        int slen=(int)s.size();
        int i=0,j=0;
        while(i<glen&&j<slen){
            if(s[j]>=g[i]){
                ans++;
                j++;
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> a={1,2,3};
    vector<int> b={1,1};
    s.findContentChildren(a,b);
    return 0;
}
