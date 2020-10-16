//
//  main.cpp
//  1467. 两个盒子中球的颜色数相同的概率
//
//  Created by 董深育 on 2020/10/15.
//

#include <iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> left, right, bas;
    int ln = 0, rn = 0;
    int alls = 0;
    double tot, ak;
    
    double fac(int a){   // 求阶乘
        double ans = 1;
        for(int i = 1; i <= a; i ++) ans *= i;
        return ans;
    }
    
    double get(vector<int>& bas){   // 求排列数
        int n = 0;
        for(auto x:bas) n += x;
        double ans = fac(n);
        for(auto x:bas) ans /= fac(x);
        return ans;
    }
    
    
    void dfs(int i){
        if(ln > alls / 2 || rn > alls / 2) return ;  // 剪枝
        if(i == left.size()){   // 叶子节点
            // for(auto x:left) cout << x << " ";
            // cout << endl;
            // for(auto x:right) cout << x <<" ";
            // cout << endl;
            int a = 0, b = 0;
            for(auto x:left){
                if(x) a ++;
            }
            for(auto x:right){
                if(x) b ++;
            }
            if(a == b)   // 两个箱子中的球的颜色种类相同
                ak += get(left) * get(right);
            return;
        }
        for(int j = 0; j <= bas[i]; j++){   // 枚举当前颜色球，左右箱子中的个数
            left[i] = j;
            right[i] = bas[i] - j;
            ln += j;   // 记录两个箱子中球的总数，用于剪枝
            rn += bas[i] - j;
            dfs(i + 1);   // 递归调用
            ln -= j;   // 恢复现场
            rn -= bas[i] - j;
        }
    }
    
    double getProbability(vector<int>& balls) {
        
        bas = balls;
        left = vector<int>(balls.size(), 0);
        right = vector<int>(balls.size(), 0);
        tot = get(balls);   // 求分母
        for(auto x:balls) alls += x;
        dfs(0);  // 求分子
        // cout << ak << " " << tot << endl;
        return ak / tot;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> balls={6,6,6,6,6,6};
    double temp=s.getProbability(balls);
    cout<<temp<<endl;
    return 0;
}
