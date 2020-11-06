//
//  main.cpp
//  1356. 根据数字二进制下 1 的数目排序
//
//  Created by 董深育 on 2020/11/6.
//

#include <iostream>
#include<vector>
using namespace std;



//class Solution {
//public:
//    inline int BitCount4(unsigned int n)
//    {
//        n = (n &0x55555555) + ((n >>1) &0x55555555) ;
//        n = (n &0x33333333) + ((n >>2) &0x33333333) ;
//        n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ;
//        n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ;
//        n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ;
//
//        return n ;
//    }
//    vector<int> sortByBits(vector<int>& arr) {
//        int len=static_cast<int>(arr.size());
//        vector<int>dp(len,-1);
//        for(int i=0;i<len;i++){
//            dp[i]=BitCount4(arr[i]);
//        }
//        //排序算法
//        for(int i=0;i<len-1;i++){
//            for(int j=0;j<len-i-1;j++){
//                if(dp[j]>dp[j+1]||(dp[j]==dp[j+1]&&arr[j]>arr[j+1])){
//                    swap(arr[j],arr[j+1]);
//                    int temp=dp[j];
//                    dp[j]=dp[j+1];
//                    dp[j+1]=temp;
//                }
//            }
//        }
//        return arr;
//    }
//};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1;i <= 10000; ++i) {
            bit[i] = bit[i>>1] + (i & 1);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr={0,1,2,3,4,5,6,7,8};
    s.sortByBits(arr);
    return 0;
}
