#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int distributeCandies(vector<int>& candies) {
        int size = (int)candies.size();
        map<int, int> mymap;
        for (int i = 0; i < size; i++) {
            //找不到
            if (mymap.find(candies[i]) == mymap.end()) {
                mymap[candies[i]] = 1;
            } else {
                mymap[candies[i]] += 1;
            }
        }
        if (mymap.size() >= size / 2) {
            return size / 2;
        }
        return mymap.size();
    }
};