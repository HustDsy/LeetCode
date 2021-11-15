#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX;
        int right = INT_MIN;
        int top = INT_MIN;
        int bottom = INT_MAX;
        int n = rectangles.size();

        set<string> s;
        int sumArea = 0;

        for (int i = 0; i < n; i++) {
            //获取四个点的坐标
            left = min(left, rectangles[i][0]);
            bottom = min(bottom, rectangles[i][1]);
            right = max(right, rectangles[i][2]);
            top = max(top, rectangles[i][3]);
            //计算总小矩形的面积
            sumArea += (rectangles[i][3] - rectangles[i][1]) *
                       (rectangles[i][2] - rectangles[i][0]);
            //分别记录小矩形的坐标
            string lt =
                to_string(rectangles[i][0]) + " " + to_string(rectangles[i][3]);
            string lb =
                to_string(rectangles[i][0]) + " " + to_string(rectangles[i][1]);
            string rt =
                to_string(rectangles[i][2]) + " " + to_string(rectangles[i][3]);
            string rb =
                to_string(rectangles[i][2]) + " " + to_string(rectangles[i][1]);
            //如果有就移除 没有就加入
            if (!s.count(lt))
                s.insert(lt);
            else
                s.erase(lt);
            if (!s.count(lb))
                s.insert(lb);
            else
                s.erase(lb);
            if (!s.count(rt))
                s.insert(rt);
            else
                s.erase(rt);
            if (!s.count(rb))
                s.insert(rb);
            else
                s.erase(rb);
        }

        //最后只剩4个大矩形坐标且面积相等即为完美矩形
        if (s.size() == 4 && s.count(to_string(left) + " " + to_string(top)) &&
            s.count(to_string(left) + " " + to_string(bottom)) &&
            s.count(to_string(right) + " " + to_string(bottom)) &&
            s.count(to_string(right) + " " + to_string(top))) {
            return sumArea == (right - left) * (top - bottom);
        }
        return false;
    }
};
