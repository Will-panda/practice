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
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

void dfs(const vector<int> &nums, vector<int> used, int step, vector<int> &status,
         vector<vector<int>> &res) {
  if (step == nums.size()) {
    res.push_back(status);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (used[i])
      continue;
    status.push_back(nums[i]);
    used[i] = 1;
    dfs(nums, used, step+1, status, res);
    status.pop_back();
    used[i] = 0;
  }
}

vector<vector<int>> permute(vector<int> &nums) {

  vector<int> used(nums.size());
  vector<int> status;
  vector<vector<int>> res;

  dfs(nums, used, 0, status, res);

  return res;
}

int main(int argc, char **argv) {

  vector<int> nums{1, 2, 3};
  auto res = permute(nums);

  for (int i = 0; i < res.size(); i++) {
    printf("%d set\n", i);
    for (auto x : res[i]) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
