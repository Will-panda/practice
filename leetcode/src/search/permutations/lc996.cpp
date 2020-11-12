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
Given an array A of non-negative integers, the array is squareful if for every
pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1
and A2 differ if and only if there is some index i such that A1[i] != A2[i].


Example 1:

Input: [1,17,8]
Output: 2
Explanation:
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
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

vector<vector<int>> BuildConnect(const vector<int> &A) {
    vector<vector<int>> connect(A.size(), vector<int>(A.size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            int sum = A[i] + A[j];
            int sqrt_n = sqrt(sum);
            if (sqrt_n * sqrt_n == sum) {
                connect[i][j] = 1;
                connect[j][i] = 1;
            }
        }
    }
    return connect;
}

void dfs(const vector<int> &A,
         const vector<vector<int>> &connect,
         vector<int> &used,
         int &ans,
         int cur,
         int d) {
    if (d == A.size()) {
        ++ans;
        return;
    }

    for (int i = 0; i < A.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && !used[i - 1] && A[i - 1] == A[i]) continue;
        if (d > 0 && !connect[cur][i]) continue;
        used[i] = 1;
        // printf("%d\n",i);
        dfs(A, connect, used, ans, i, d + 1);
        used[i] = 0;
    }
}

int DFSSolution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    auto connect = BuildConnect(A);
    vector<int> used(A.size(), 0);
    int ans = 0;

    dfs(A, connect, used, ans, 0, 0);
    return ans;
}

int DPSolution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    auto connect = BuildConnect(A);
    int n = A.size();
    // status
    int status_space = 1 << n;
    vector<vector<int>> dp(status_space, vector<int>(n, 0));

    // init
    for (int i = 0; i < n; ++i) {
        if (i > 0 && A[i - 1] == A[i]) continue;
        dp[1 << i][i] = 1;
    }

    for (int s = 0; s < status_space; ++s) {  // start
        for (int i = 0; i < n; ++i) {
            if (!dp[s][i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!connect[i][j]) continue;
                if (s & (1 << j)) continue;
                if (j > 0 && !(s & (1 << j - 1)) && A[j - 1] == A[j]) continue;
                dp[s | 1 << j][j] += dp[s][i];
            }
        }
    }
    int ans = 0;
    int s = status_space - 1;
    for (int i = 0; i < n; i++) {
        if (dp[s][i] > 0) ans += dp[s][i];
    }
    return ans;
}

int numSquarefulPerms(vector<int> &A) {
    int res;
    // res = DPSolution(A);
    res = DFSSolution(A);

    return res;
}

int main(int argc, char **argv) {
    vector<int> test{1, 17, 8};
    // gctaagttcatgcatc
    int res;
    // res = numSquarefulPerms(test);
    // std::cout << res << std::endl;

    // vector<int> test2{2, 2, 2};
    // res = numSquarefulPerms(test2);
    // std::cout << res << std::endl;

    // vector<int> test3{1, 1, 8, 1, 8};
    // res = numSquarefulPerms(test3);
    // std::cout << res << std::endl;

    vector<int> test4{2, 2, 7, 7, 2};
    res = numSquarefulPerms(test4);
    std::cout << res << std::endl;

    return 0;
}
