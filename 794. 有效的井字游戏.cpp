#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /**
     * 1. X的个数等于O的个数或者X的个数比O的个数多一 其余情况为 false
     * 2. X获胜，此时X的个数比O少 return false
     * 3. O获胜，此时O的个数不等于X的个数 return false
     * 4. 其余情况为true
     */
    bool validTicTacToe(vector<string>& board) {
        int XCount = 0, OCount = 0;
        for (string s : board) {
            for (char c : s) {
                c == 'X' ? XCount++ : XCount;
                c == 'O' ? OCount++ : OCount;
            }
        }
        if (!(XCount == OCount || XCount == OCount + 1)) {
            return false;
        }
        if (check(board, 'X') && XCount != OCount + 1) {
            return false;
        }
        if (check(board, 'O') && XCount != OCount) {
            return false;
        }
        return true;
    }

    bool check(vector<string>& board, char c) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                return true;
            }
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                return true;
            }
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
            return true;
        }
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
            return true;
        }
        return false;
    }
};