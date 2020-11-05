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
Given two integers n and k, return all possible combinations of k numbers out of
1 ... n.

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

void dfs(
    int n, size_t k, int step, vector<int> &status, vector<vector<int>> &res) {
    if (status.size() == k) {
        res.push_back(status);
        return;
    }
    for (int i = step; i <= n; i++) {
        status.push_back(i);
        dfs(n, k, i + 1, status, res);
        status.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> status;
    vector<vector<int>> res;

    dfs(n, k, 1, status, res);

    return res;
}

int main(int argc, char **argv) {
    auto res = combine(4, 2);

    for (unsigned int i = 0; i < res.size(); i++) {
        printf("%u set\n", i);
        for (auto x : res[i]) {
            std::cout << x << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
