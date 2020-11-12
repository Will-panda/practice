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
    void dfs(vector<string>& ans, string& cur, int l, int r, int n) {
        if (l == n && r == n) {
            ans.push_back(cur);
            return;
        }
        if (l < n) {
            cur.push_back('(');
            dfs(ans, cur, l + 1, r, n);
            cur.pop_back();
        }
        if (r < l && r < n) {
            cur.push_back(')');
            dfs(ans, cur, l, r + 1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        dfs(ans, cur, 0, 0, n);
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution so;
    vector<string> ans;
    try {
        ans = so.generateParenthesis(3);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    for (auto s : ans) {
        printf("%s\n", s.c_str());
    }

    return 0;
}
