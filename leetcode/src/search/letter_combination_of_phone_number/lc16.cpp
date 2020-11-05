/*
 * Copyright(C) liwenqiang<liwq93@163.com>
 * All rights reserved
 */
#include <string>
#include <vector>

using std::vector;
using std::string;

void dfs(const vector<string> &table, string &status, int step,
         vector<string> res);

vector<string> letterCombinations(string digits);

int main(int argc, char **argv) { return 0; }

vector<string> letterCombinations(string digits) {
  vector<string> table{"",    "",    "abc",  "def", "ghi",
                       "jkl", "mno", "qprs", "tuv", "wxyz"};
  string status = "";
  int step = 0;
  vector<string> res;

  dfs(table, digits, status, step, res);
  return res;
}

void dfs(const vector<string> &table, const string &digits, string &status,
         int step, vector<string> res) {
  if (step == digits.size()) {
    res.push_back(status);
    return;
  }

  for (const auto &digit : table[digits[step] - '0']) {
    status.push_back(digit);
    dfs(table, digits, status, step, res);
    status.pop_back();
  }
}
