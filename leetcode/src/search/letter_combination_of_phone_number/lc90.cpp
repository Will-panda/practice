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
 *  Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *  Note: The solution set must not contain duplicate subsets.
*/

void dfs(const vector<int> &nums, int d, vector<int> &status,
         vector<vector<int>> &res) {
  res.push_back(status);
  for (int i = d; i < nums.size(); i++) {
    if (i > d && nums[i] == nums[i - 1])
      continue;
    status.push_back(nums[i]);
    dfs(nums, i + 1, status, res);
    status.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  if (nums.empty())
    return {};
  std::sort(nums.begin(), nums.end());

  vector<int> status;
  vector<vector<int>> res;

  dfs(nums, 0, status, res);

  return res;
}

int main(int argc, char **argv) {
  vector<int> candidate{1, 2};

  auto res = subsetsWithDup(candidate);

  for (int i = 0; i < res.size(); i++) {
    printf("%d set\n", i);
    for (auto x : res[i]) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
