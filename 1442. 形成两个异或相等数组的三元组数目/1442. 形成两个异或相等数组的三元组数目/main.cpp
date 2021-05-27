//
//  main.cpp
//  1442. 形成两个异或相等数组的三元组数目
//
//  Created by dsy on 2021/5/18.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>s(n+1);
        for(int i=0;i<n;i++){
            s[i+1]=s[i]^arr[i];
        }
        //记录当走到k时，有多少个i等于k
        //total记录着等于k时i1+i2+..im
        unordered_map<int,int>cnt,total;
        int ans=0;
        for(int k=0;k<n;k++){
            if(cnt.count(s[k+1])){
                ans+=cnt[s[k+1]]*k-total[s[k+1]];
            }
            //这个时候当等于k的时候
            cnt[s[k]]++;
            total[s[k]]+=k;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
