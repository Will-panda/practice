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
Given an array A of strings, find any smallest string that contains each string
in A as a substring.

We may assume that no string in A is substring of another string in A.


Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be
accepted.
Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
*/

void dfs(const vector<string> &A, int step, vector<int> &used, string &cur,
         string &ans) {
  if (step == A.size()) {
    if (cur.size() < ans.size())
      ans = cur;
    return;
  }
  for (int i = 0; i < A.size(); ++i) {
    if (used[i])
      continue;
    used[i] = 1;
    // merge A[i] with cur
    int j = 0;
    int k = 0;
    int origin_n = cur.size();
    while (j < cur.size()) {
      while (j < cur.size() && k < A[i].size() && cur[j] == A[i][k]) {
        k++;
        j++;
      }
      if (j < cur.size()) {
        j++;
        k = 0;
      }
    }
    while (k < A[i].size()) {
      cur.push_back(A[i][k]);
      k++;
    }
    dfs(A, step + 1, used, cur, ans);
    cur = cur.substr(0, origin_n);
    used[i] = 0;
  }
}
void printCost(vector<vector<int>> cost) {
  for (int i = 0; i < cost.size(); i++) {
    for (int j = 0; j < cost.size(); j++) {
      printf("(%d, %d)=%d\n", i, j, cost[i][j]);
    }
  }
}

int calCost1(string &A, string &B) {
  int cost = 0;
  for (int k = 1; k <= std::min(A.size(), B.size()); k++) {
    if (A.substr(A.size() - k) == B.substr(0, k)) {
      cost = k;
    }
  }
  return cost;
}

int calCost2(string &A, string &B) {
  int j = 0;
  int k = 0;

  while (j < A.size() && k < B.size()) {
    if (A[j] == B[k]) {
      k++;
      j++;
    } else {
      if (k != 0) {
        k = 0;
      } else {
        j++;
      }
    }
  }

  return k;
}

string shortestSuperstring(vector<string> &A) {

  string cur;
  vector<int> used(A.size());
  vector<vector<int>> cost(A.size(), vector<int>(A.size()));

  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A.size(); j++) {
      auto str_i = A[i];
      auto str_j = A[j];
      cost[i][j] = str_j.size();
      // auto k1 = calcost(A[i], A[j]);
      auto k2 = calCost2(A[i], A[j]);
      // if (k1 != k2) {
      //   std::cout << A[i] << " + " << A[j] << " k1: " << k1 << ",  k2: " << k2
      //             << std::endl;
      // }
      cost[i][j] = str_j.size() - k2;
    }
  }
  // printcost(cost1);
  string ans;
  for (auto &s : A) {
    ans += s;
  }

  // dfs(A, 0, used, cur, ans);

  return ans;
}

int main(int argc, char **argv) {

  vector<string> test{"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  auto res = shortestSuperstring(test);
  // std::cout << res << std::endl;

  vector<string> test2{"alex", "loves", "leetcode"};
  res = shortestSuperstring(test2);
  // std::cout << res << std::endl;

  return 0;
}
