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
Remove the minimum number of invalid parentheses in order to make the input
string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/

class Solution {
 public:
    bool isVlad(const string& s) {
        int l = 0;
        for (const auto& c : s) {
            l += static_cast<int>(c == '(');
            l -= static_cast<int>(c == ')');
            if (l < 0) return false;
        }
        return l == 0;
    }
    void dfs(const string& s, vector<string>& ans, int l, int r, int step) {
        if (l == 0 && r == 0) {
            if (isVlad(s)) ans.push_back(s);
            return;
        }
        for (int i = step; i < s.size(); ++i) {
            if (i > step && s[i - 1] == s[i]) continue;
            if (s[i] != '(' && s[i] != ')') continue;
            string cur = s;
            cur.erase(i, 1);
            if (l > 0 && s[i] == '(') {
                dfs(cur, ans, l - 1, r, i);
            }
            if (r > 0 && s[i] == ')') {
                dfs(cur, ans, l, r - 1, i);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        vector<string> ans;
        for (const auto& c : s) {
            l += static_cast<int>(c == '(');
            if (l == 0) {
                r += static_cast<int>(c == ')');
            } else {
                l -= static_cast<int>(c == ')');
            }
        }
        printf("l %d ; r %d\n", l, r);
        dfs(s, ans, l, r, 0);
        return ans;
    }
};

int main(int argc, char** argv) {
    std::string test1(")(");
    Solution so;
    auto ans = so.removeInvalidParentheses(test1);
    for (auto s : ans) {
        printf("%s\n", s.c_str());
    }

    return 0;
}
