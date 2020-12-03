/*
 * Copyright(C) liwenqiang<liwq93@163.com>
 * All rights reserved
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::vector;
using std::string;

/** Description:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space,
respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown
above
Example 2:
Input: n = 1
Output: [["Q"]]
*/

class Solution {
 public:
    vector<int> col_, mask_, reverse_mask_;
    vector<int> queen_;
    vector<vector<int>> vec_queen_;
    void dfs(int n, int cur_i) {
        if (cur_i == n) {
            vec_queen_.push_back(queen_);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col_[j]) continue;
            if (mask_[cur_i + j]) continue;
            if (reverse_mask_[cur_i + n - 1 - j]) continue;
            queen_[cur_i] = j;
            col_[j] = 1;
            mask_[cur_i + j] = 1;
            reverse_mask_[cur_i + n - 1 - j] = 1;
            dfs(n, cur_i + 1);
            queen_[cur_i] = 0;
            col_[j] = 0;
            mask_[cur_i + j] = 0;
            reverse_mask_[cur_i + n - 1 - j] = 0;
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        col_ = vector<int>(n, 0);
        mask_ = vector<int>(2* n, 0);
        queen_ = vector<int>(n, 0);
        reverse_mask_ = vector<int>(n + 1, 0);
        dfs(n, 0);
        vector<vector<string>> ans;
        for (auto queen:vec_queen_) {
            vector<string> cur_ans(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                cur_ans[i][queen[i]] = 'Q';
            }
            ans.push_back(cur_ans);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution so;
    vector<vector<string>> res = so.solveNQueens(4);
    for (auto row : res) {
        for (auto ch : row) {
            std::cout << " " << ch << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
