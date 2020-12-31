//
//  main.cpp
//  188. 买卖股票的最佳时机 IV
//
//  Created by dsy on 2020/12/28.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>up_num;
        vector<int>down_num;
        int len=prices.size();
        if(len==0||len==1||k==0) return 0;
        int begin=0;
        int end=0;
        for(int i=0;i<len-1;i++){
            if(prices[i]<prices[i+1]){
                begin=i;
                while(i<len-1&&prices[i]<prices[i+1]){
                    i++;
                }
                end=i;
                up_num.push_back(prices[end]-prices[begin]);
            }
            if(prices[i]>prices[i+1]){
                begin=i;
                while(i<len-1&&prices[i]>prices[i+1]){
                    i++;
                }
                end=i;
                up_num.push_back(prices[end]-prices[begin]);
            }
        }
        //接下来做筛选
        int ans=0;
        int size_up=up_num.size();
        sort(up_num.begin(), up_num.end());
        sort(down_num.begin(), down_num.end());
        if(size_up<=k){
            int a=up_num.size()-1;
            for(int i=0;i<k&&i<up_num.size();i++){
                ans+=up_num[a];
                a--;
            }
        }else{
            //开始筛选
            int evict_num=size_up-k;
            int i=0;
            int j=0;
            int tt=0;
            while(tt<evict_num){
                int up=up_num[i];
                int down=down_num[j];
                if(up<=down){
                    //剔除掉这个数据
                    i++;
                }else{
                    //合并
                }
                tt++;
            }
        }
        return ans;
    
    }
};

int main(int argc, const char * argv[]) {
    vector<int>prices={1,2};
    Solution s;
    cout<<s.maxProfit(1,prices);
    return 0;
}
