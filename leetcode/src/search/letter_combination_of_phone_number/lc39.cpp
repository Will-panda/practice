/*
 * Copyright(C) liwenqiang<liwq93@163.com>
 * All rights reserved
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

void dfs(const vector<int> &candidates, int step, int &sum,
         vector<int> &status, int target, vector<vector<int>> &res) {
  if (target == sum) {
    res.push_back(status);
    return;
  }
  if (sum > target) {
    return;
  }

  for (int i = step; i < candidates.size(); i++) {
    int num = candidates[i];
    sum += num;
    status.push_back(num);
    dfs(candidates, i, sum, status, target, res);
    sum -= num;
    status.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  if (candidates.empty())
    return {};
  std::sort(candidates.begin(), candidates.end());

  int sum = 0;
  int step = 0;
  vector<int> status;
  vector<vector<int>> res;

  dfs(candidates, step, sum, status, target, res);
  return res;
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
