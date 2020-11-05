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
Given a string S, we can transform every letter individually to be lowercase or
uppercase to create another string.

Return a list of all possible strings we could create. You can return the output
in any order.

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
*/

void dfs(const string &S, int step, string &status, vector<string> &res) {
  if (step == S.size()) {
    res.push_back(status);
    return;
  }
  dfs(S, step + 1, status, res);
  if (!isalpha(S[step]))
    return;
  status[step] ^= (1<<5);
  dfs(S, step + 1, status, res);
  status[step] ^= (1<<5);

}

vector<string> letterCasePermutation(string S) {

  string cur(S);
  vector<string> res;
  dfs(S, 0, cur, res);

  return res;
}

int main(int argc, char **argv) {

  string test("a1b2");
  auto res = letterCasePermutation(test);

  for (int i = 0; i < res.size(); i++) {
    printf("%d set\n", i);
    std::cout << res[i] << ", ";

    std::cout << std::endl;
  }
  return 0;
}
