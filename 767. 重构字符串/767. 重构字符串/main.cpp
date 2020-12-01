//
//  main.cpp
//  767. 重构字符串
//
//  Created by dsy on 2020/11/30.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        string reorganizeArray(length, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                counts[i]--;
                oddIndex += 2;
            }
            while (counts[i] > 0) {
                reorganizeArray[evenIndex] = c;
                counts[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    s.reorganizeString("aab");
    return 0;
}
