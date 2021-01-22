//
//  main.cpp
//  1584. 连接所有点的最小费用
//
//  Created by dsy on 2021/1/19.
//

#include <iostream>
#include<vector>
using namespace std;

class Djset{
public:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    vector<int>len;
    int num;
    Djset(int n): parent(n), rank(n), len(n, 0), size(n, 1), num(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    int merge(int x, int y, int length) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            // rooty的父节点设置为rootx,同时将rooty的节点数和边长度累加到rootx,
            size[rootx] += size[rooty];
            len[rootx] += len[rooty] + length;
            // 如果某个连通分量的节点数 包含了所有节点，直接返回边长度
            if (size[rootx] == num) return len[rootx];
        }
        return -1;
    }
};

struct Edge {
    int start; // 顶点1
    int end;   // 顶点2
    int len;   // 长度
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        Djset ds(n);
        vector<Edge> edges;
        // 建立点-边式数据结构
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Edge edge = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }
        // 按边长度排序
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a.len < b.len;
        });

        // 连通分量合并
        for (auto& e : edges) {
           res = ds.merge(e.start, e.end, e.len);
           if (res != -1) return res;
        }
        return 0;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
