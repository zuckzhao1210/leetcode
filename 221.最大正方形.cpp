// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem221.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        vector<vector<bool>> flags;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (flags[i][j] || flags[i][j] == 0) continue;
                ret = max()
            }
        }
    }

    // 判断是否是正方形
    int maxSquare(vector<vector<char>>& matrix, int x_min, int y_min, int x_max, int y_max) {
        int len = x_max - x_min;
        int n = matrix.size();
        int m = matrix[0].size();
        if (x_max < matrix.size())
        }
    }
};
// @lc code=end

