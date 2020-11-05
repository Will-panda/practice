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

int calCost2(const string &A, const string &B) {
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

vector<vector<int>> BuildPathCost(const vector<string> &A) {
    vector<vector<int>> cost(A.size(), vector<int>(A.size()));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            auto str_i = A[i];
            auto str_j = A[j];
            cost[i][j] = str_j.size();
            auto k2 = calCost2(A[i], A[j]);
            cost[i][j] = str_j.size() - k2;
        }
    }
    return cost;
}

void dfs(const vector<string> &A,
         const vector<vector<int>> &cost,
         int used,
         unsigned int step,
         int total_cost,
         int &min_cost,
         vector<int> &path,
         vector<int> &ans_path) {
    if (total_cost > min_cost) return;
    if (step == A.size()) {
        min_cost = total_cost;
        ans_path = path;
        return;
    }
    for (int i = 0; i < A.size(); ++i) {
        if (used & (1 << i)) continue;
        // update current cost
        path[step] = i;
        int cur_cost;
        int pre_ndoe = path[step - 1];
        if (step > 0) {
            cur_cost = cost[pre_ndoe][i];
        } else {
            cur_cost = A[i].length();
        }
        total_cost += cur_cost;
        // printf("cur depth %d\n", step);
        // printf("cur node %d\n", i);
        // printf("cur string %s, cost %d\n", A[i].c_str(), cur_cost);
        // printf("total cost %d\n\n", total_cost);

        dfs(A, cost, used | (1 << i), step + 1, total_cost, min_cost, path,
            ans_path);
        total_cost -= cur_cost;
    }
}

string DFSSolution(vector<string> &A) {
    string ans;
    auto n = A.size();
    auto cost = BuildPathCost(A);
    auto path = vector<int>(n, -1);
    auto ans_path = vector<int>(n, -1);

    int total_cost = 0;
    int min_cost = __INT_MAX__;
    dfs(A, cost, 0, 0, total_cost, min_cost, path, ans_path);
    ans = A[ans_path[0]];
    printf("%d \n", ans_path[0]);
    for (int k = 1; k < ans_path.size(); k++) {
        printf("%d\n", ans_path[k]);
        auto i = ans_path[k - 1];
        auto j = ans_path[k];
        ans += A[j].substr(A[j].length() - cost[i][j]);
    }
    return ans;
}

string DPSolution(vector<string> &A) {
    auto cost = BuildPathCost(A);
    string ans;
    int n = A.size();
    // status
    int status_space = 1 << n;
    vector<vector<int>> dp(status_space, vector<int>(n, __INT_MAX__ / 2));
    vector<vector<int>> parent(status_space, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    for (int s = 1; s < status_space; s++) {
        for (int j = 0; j < n; j++) {
            if (!(s & (1 << j))) continue;
            int pre_s = s & ~(1 << j);
            for (int i = 0; i < n; i++) {
                if (!(pre_s & (1 << i))) continue;
                if (dp[pre_s][i] + cost[i][j] < dp[s][j]) {
                    dp[s][j] = dp[pre_s][i] + cost[i][j];
                    parent[s][j] = i;
                }
            }
        }
    }

    int s = status_space - 1;
    auto last_dp = dp[s];
    auto j = std::min_element(last_dp.begin(), last_dp.end()) - last_dp.begin();

    while (true) {
        printf("%d \n", j);
        auto i = parent[s][j];
        if (i < 0) {
            ans = A[j] + ans;
            printf("\n\n");

            return ans;
        } else {
            ans = A[j].substr(A[j].size() - cost[i][j]) + ans;
        }
        s = s & ~(1 << j);
        j = i;
    }
}

string shortestSuperstring(vector<string> &A) {
    auto ans1 = DPSolution(A);
    auto ans2 = DFSSolution(A);
    return ans2;
}

int main(int argc, char **argv) {
    vector<string> test{"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    // gctaagttcatgcatc
    auto res = shortestSuperstring(test);
    std::cout << res << std::endl;

    vector<string> test2{"alex", "loves", "leetcode"};
    res = shortestSuperstring(test2);
    std::cout << res << std::endl;

    return 0;
}
