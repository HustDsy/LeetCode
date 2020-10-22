//
//  main.cpp
//  763. 划分字母区间
//
//  Created by 董深育 on 2020/10/22.
//

#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        //遍历S，找出所有字母出现的单个次数
        vector<int>ans;
        vector<int>chars(26,-1);
        map<int, pair<int, int>>points;
        //从出现的开端由小到大排序
        for(int i=0;i<S.length();i++){
            //如果找到了字母,更新最后的端点即可
            int target=S[i]-'a';
            if(points.find(chars[target])!=points.end()){
                points[chars[target]].second=i;
            }else{
                //没有找到字母的话，那么就直接更新起始点,并且记录这个字母的起始点
                chars[target]=i;
                points[i]=make_pair(i,i);
            }
        }
        //开始合并区间
        map<int,pair<int,int>>::iterator it;
        for(it=points.begin();it!=points.end();){
            int x=it->second.first;
            int y=it->second.second;
            for(it++;it!=points.end();it++){
                int xx=it->second.first;
                int yy=it->second.second;
                if(xx>y){
                    ans.push_back(y-x+1);
                    break;
                }else{
                    y=max(y,yy);
                }
            }
            if(it==points.end()){
                ans.push_back(y-x+1);
            }
        }
        
        return ans;
    }
    
    vector<int> partitionLabels_(string S) {
            int last[26];
            int length = S.size();
            for (int i = 0; i < length; i++) {
                last[S[i] - 'a'] = i;
            }
            vector<int> partition;
            int start = 0, end = 0;
            for (int i = 0; i < length; i++) {
                end = max(end, last[S[i] - 'a']);
                if (i == end) {
                    partition.push_back(end - start + 1);
                    start = end + 1;
                }
            }
            return partition;
        }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
