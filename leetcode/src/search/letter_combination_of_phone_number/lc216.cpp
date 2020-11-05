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
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 * - Only numbers 1 through 9 are used.
 * - Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain
 * the
 * same combination twice, and the combinations may be returned in any order.
*/

void dfs(const vector<int> &nums, int step_limit, int target, int step,
         vector<int> &status, vector<vector<int>> &res) {
  if (target == 0 && status.size() == step_limit) {
    res.push_back(status);
    return;
  }
  for (int i = step; i < nums.size(); i++) {
    if (nums[i] > target)
      return;
    status.push_back(nums[i]);
    dfs(nums, step_limit, target - nums[i], i + 1, status, res);
    status.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};

  vector<int> status;
  vector<vector<int>> res;

  dfs(nums, k, n, 0, status, res);

  return res;
}

int main(int argc, char **argv) {

  auto res = combinationSum3(3, 7);

  for (int i = 0; i < res.size(); i++) {
    printf("%d set\n", i);
    for (auto x : res[i]) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
