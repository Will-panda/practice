/*
 * Copyright(C) liwenqiang<liwq93@163.com>
 * All rights reserved
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::vector;
using std::string;

/** Description:
 * Given an array of distinct integers candidates and a target integer target,
 return a list of all unique combinations of candidates where the chosen numbers
 sum to target. You may return the combinations in any order.

 * The same number may be chosen from candidates an unlimited number of times.
 Two combinations are unique if the frequency of at least one of the chosen
 numbers is different.

 * It is guaranteed that the number of unique combinations that sum up to target
 is less than 150 combinations for the given input.
*/

void dfs(const vector<int> &candidates, int target, int d, vector<int> &status,
         std::set<vector<int>> &res) {
  if (target == 0) {
    res.insert(status);
    return;
  }
  for (int i = d; i < candidates.size(); i++) {
    if (candidates[i] > target)
      return;
    if (i > 0 && candidates[i-1] ==  candidates[i]) continue;
    status.push_back(candidates[i]);
    dfs(candidates, target - candidates[i], i + 1, status, res);
    status.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  if (candidates.empty())
    return {};
  std::sort(candidates.begin(), candidates.end());

  vector<int> status;
  std::set<vector<int>> res;


  dfs(candidates, target, 0, status, res);
  return vector<vector<int>>(res.begin(), res.end());
}

int main(int argc, char **argv) {
  vector<int> candidate{1, 2};

  auto res = combinationSum(candidate, 3);

  for (auto vec_x : res) {
    for (auto x : vec_x) {
      std::cout << x << " " << std::endl;
    }
    std::cout << "____" << std::endl;
  }
  return 0;
}
