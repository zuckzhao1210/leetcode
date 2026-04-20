// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem73.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroFirstCol;    // 首列是否为0 j=0时
        bool isZeroFirstRow;    // 首行是否为0 i=0时
        // 用首行和首列标记记录
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                int value = matrix[i][j];
                if (value != 0)
                {
                    continue;
                }
                else
                {
                    // 不是首行首列，用首行和首列记录置零
                    if (i != 0 && j != 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                        continue;
                    }
                    // 如果是首行或者首列，单独记下来
                    if (i == 0)
                        isZeroFirstRow = true;
                    if (j == 0)
                        isZeroFirstCol = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (i != 0 && j != 0)
                {
                    matrix[i][j] = (matrix[0][j] == 0 || matrix[i][0] == 0) ? 0 : matrix[i][j];
                }
            }
        }
        if (isZeroFirstRow)
        {
            for (int i = 0; i < matrix[0].size(); ++i)
            {
                matrix[0][i] = 0;
            }
        }
        if (isZeroFirstCol)
        {
            for (int i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
// @lc code=end

