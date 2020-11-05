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
Given a collection of numbers that might contain duplicates, return all possible
unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

void dfs(const vector<int> &nums, vector<int> &used, int step,
         vector<int> &status, vector<vector<int>> &res) {
  if (step == nums.size()) {
    res.push_back(status);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (used[i] == 1)
      continue;
    if (i > 0 && nums[i] == nums[i - 1] && used[i-1] == 0)
      continue;
    used[i] = 1;

    status.push_back(nums[i]);
    dfs(nums, used, step + 1, status, res);
    status.pop_back();
    used[i] = 0;
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
  std::sort(nums.begin(), nums.end());

  vector<int> used(nums.size(), 0);
  vector<int> status;
  vector<vector<int>> res;

  dfs(nums, used, 0, status, res);

  return res;
}

int main(int argc, char **argv) {

  vector<int> nums{1, 1, 2};
  auto res = permuteUnique(nums);

  for (int i = 0; i < res.size(); i++) {
    printf("%d set\n", i);
    for (auto x : res[i]) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
