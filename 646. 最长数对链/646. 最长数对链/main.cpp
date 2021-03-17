//
//  main.cpp
//  646. 最长数对链
//
//  Created by dsy on 2021/3/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,1);
        if(n==0||n==1) return n;
        int ans=dp[0];
        sort(pairs.begin(),pairs.end(),[](auto&a,auto&b)->bool{
           return a[0]<b[0];
        });
        for(int i=1;i<=n-1;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int> > pairs={{3,10},{3,7},{7,10},{7,9},{-1,7},{-9,5},{2,8}};
    cout<<s.findLongestChain(pairs);
    return 0;
}
