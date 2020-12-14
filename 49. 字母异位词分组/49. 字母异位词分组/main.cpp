//
//  main.cpp
//  49. 字母异位词分组
//
//  Created by dsy on 2020/12/14.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int len=(int)strs.size();
        vector<int>dp(len,0);
        vector<string>tags;
        for(int i=0;i<len;i++){
            string tag(26,'0');
            int leni=(int)strs[i].length();
            for(int j=0;j<leni;j++){
                tag[strs[i][j]-'a']+=1;
            }
            tags.emplace_back(tag);
        }
        for(int i=0;i<len;i++){
            if(!dp[i]){
                dp[i]=1;
                vector<string>temp;
                temp.emplace_back(strs[i]);
                for(int j=i+1;j<len;j++){
                    if(!dp[j]&&tags[i]==tags[j]){
                        dp[j]=1;
                        temp.emplace_back(strs[j]);
                    }
                }
                ans.emplace_back(temp);
            }
        }
        return  ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>strs={"ddddddddddg","dgggggggggg"};
    s.groupAnagrams(strs);
    
    return 0;
}
