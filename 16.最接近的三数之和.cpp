// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem16.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end() - 1, std::less<int>());
        int i = 0; j = nums.size() - 1;
        int distance
        while (i + 1 < j) {
            int lt = target - nums[i] - nums[j];
            int n = (i + j) / 2;
            
        }

    }
};
// @lc code=end

