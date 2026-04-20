// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem190.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        std::string bits;
        while (n / 2 > 0) {
            int bit = n % 2;
            n = n / 2;
            bits.push_back((char)bit);
        }
        if (n == 1) {
            bits.push_back('1');
        }
        int ret = 0;
        for (int i = 0; i < bits.size(); i++) {
            int bit = (int) bits[i];
            ret = ret + bit * (std::pow(2, (bits.size() - 1 - i)));
        }
        return ret;
    }
};
// @lc code=end

