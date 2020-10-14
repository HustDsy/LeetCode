//
//  main.cpp
//  1002. 查找常用字符
//
//  Created by 董深育 on 2020/10/14.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string>ans;
        int len=(int)A.size();
        vector<vector<int>>records(len,vector<int>(26,0));
        for(int i=0;i<len;i++){
            string s=A[i];
            for(int j=0;j<s.length();j++){
                records[i][s[j]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(records[0][i]!=0){
                int minret=records[0][i];
                for(int j=1;j<len;j++){
                    minret=min(minret,records[j][i]);
                }
                for(int k=0;k<minret;k++){
                    char num='a'+i;
                    string aa;
                    aa.push_back(num);
                    ans.push_back(aa);
                    cout<<ans.back();
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>A={"cool","lock","cook"};
    s.commonChars(A);
    return 0;
}
