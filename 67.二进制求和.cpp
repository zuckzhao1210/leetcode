// @before-stub-for-debug-begin
#include "commoncppproblem67.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ret;
        int i = 0;
        int m = 0;
        // 从后往前遍历字符串
        while (i < a.size() && i < b.size()) {
            char ia = a[a.size() - 1 - i];
            char ib = b[b.size() - 1 - i];
            int sum = (int) ia + (int) ib + m;
            switch (sum) {
                case 0:
                    ret.push_back(sum);
                    m = 0;
                    break;
                case 1:
                    ret.push_back(sum);
                    m = 0;
                    break;
                case 2:
                    ret.push_back(0);
                    m = 1;
                    break;
                case 3:
                    ret.push_back(1);
                    m = 1;
            }
        }
        for (int j = 0; j < ret.size() / 2; j++) {
            char temp = ret[j];
            ret[j] = ret[ret.size() - 1 - j];
            ret[ret.size() - 1 - j] = temp;
        }
        return ret;
    }
};
// @lc code=end
