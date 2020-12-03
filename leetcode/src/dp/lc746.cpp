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
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
indexed).

Once you pay the cost, you can either climb one or two steps. You need to find
minimum cost to reach the top of the floor, and you can either start from the
step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
cost[3].

*/

int minCostClimbingStairs(vector<int>& cost) {
    if (cost.size() < 3) return *(std::min_element(cost.begin(), cost.end()));
    int min_cost_first = cost[0];
    int min_cost_second = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
        int temp = min_cost_first;
        min_cost_first = min_cost_first < min_cost_second
                             ? (cost[i] + min_cost_first)
                             : (cost[i] + min_cost_second);
        min_cost_second = temp;
    }
    return min_cost_first < min_cost_second ? min_cost_first : min_cost_second;
}

int main(int argc, char** argv) {
    vector<int> test1 = {0,1,1,0};

    return 0;
}
