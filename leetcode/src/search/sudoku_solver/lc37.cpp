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
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of
the grid.
The '.' character indicates empty cells.

Example 1:
Input: board =
[
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
Output:
[
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
*/

class Solution {
 public:
    vector<vector<int>> col_, row_, box_;
    bool dfs(vector<vector<char>>& board, int cur_i, int cur_j) {
        if (cur_i == 9) {
            return true;
        }
        auto nex_i = cur_i;
        auto nex_j = (cur_j + 1) % 9;
        if (nex_j == 0) ++nex_i;
        if (board[cur_i][cur_j] != '.') return dfs(board, nex_i, nex_j);
        for (int i = 1; i <= 9; i++) {
            int box_key = (cur_i / 3) * 3 + cur_j / 3;
            if (col_[cur_j][i] || row_[cur_i][i] || box_[box_key][i]) continue;
            col_[cur_j][i] = 1;
            row_[cur_i][i] = 1;
            box_[box_key][i] = 1;
            board[cur_i][cur_j] = i + '0';
            if (dfs(board, nex_i, nex_j)) return true;
            col_[cur_j][i] = 0;
            row_[cur_i][i] = 0;
            box_[box_key][i] = 0;
            board[cur_i][cur_j] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        col_ = vector<vector<int>>(9, vector<int>(10, 0));
        row_ = vector<vector<int>>(9, vector<int>(10, 0));
        box_ = vector<vector<int>>(9, vector<int>(10, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                col_[j][num] = 1;
                row_[i][num] = 1;
                box_[(i / 3) * 3 + j / 3][num] = 1;
            }
        }
        if (dfs(board, 0, 0)) {
            printf("succeed!\n");
        } else {
            printf("failed!\n");
        }
    }
};

int main(int argc, char** argv) {
    Solution so;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    so.solveSudoku(board);

    for (auto row : board) {
        for (auto ch : row) {
            std::cout << " " << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}
