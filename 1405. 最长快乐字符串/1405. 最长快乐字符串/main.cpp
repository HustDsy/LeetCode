//
//  main.cpp
//  1405. 最长快乐字符串
//
//  Created by 董深育 on 2020/10/29.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(int pos, const string &str, const string &ch) {
        string a = str;
        a.insert(pos, ch);
        for(int i = 0; i+2 < a.size(); i++) {
            if(a[i] == ch[0] && a[i+1] == ch[0] && a[i+2] == ch[0]) {
                return false;
            }
        }
        return true;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, string>> vec;
        vec.push_back(make_pair(a, string("a")));
        vec.push_back(make_pair(b, string("b")));
        vec.push_back(make_pair(c, string("c")));
        sort(vec.begin(), vec.end());
        string str;
        while(vec[0].first > 0) {
            vec[0].first --;
            vec[1].first --;
            vec[2].first --;
            str += vec[2].second;
            str += vec[1].second;
            str += vec[0].second;
        }
        while(vec[1].first > 0) {
            vec[1].first --;
            vec[2].first --;
            str += vec[2].second;
            str += vec[1].second;
        }
        while(vec[2].first > 0) {
            bool flag = false;
            for(int i = 0; i <= str.size(); i++) {
                if(check(i, str, vec[2].second)) {
                    str.insert(i, vec[2].second);
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                break;
            }
            vec[2].first --;
        }
        return str;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
