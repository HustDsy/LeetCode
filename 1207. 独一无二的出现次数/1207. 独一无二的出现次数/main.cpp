//
//  main.cpp
//  1207. 独一无二的出现次数
//
//  Created by 董深育 on 2020/10/28.
//

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>dp(2001,0);
        for(int i=0;i<arr.size();i++){
            dp[arr[i]+1000]++;
        }
        int nums=0;
        for(int i=0;i<2001;i++){
            if(dp[i]!=0){
                nums++;
            }
        }
        unordered_set<int>set_;
        for(int i=0;i<arr.size();i++){
            set_.insert(dp[arr[i]+1000]);
        }
        return set_.size()==nums;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr={1,2,2,1,1,3};
    s.uniqueOccurrences(arr);
    return 0;
}
