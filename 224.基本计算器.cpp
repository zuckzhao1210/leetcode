// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem224.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<char> st;
        for (const char &c : s)
        {
            // 遇到右括号，进行一次计算
            if (c == ')')
            {
                simpleCalculate(st, true);
            }
            else if (c != ' ')
            {
                st.push(c);
            }
        }
        simpleCalculate(st, false);
        string ret_string;
        while (st.size())
        {
            ret_string = st.top() + ret_string;
            st.pop();
        }
        return stoi(ret_string);
    }

    // 对栈里的字符进行一次括号中的运算
    void simpleCalculate(stack<char> & st, bool isInner)
    {
        string value;
        int ret = 0;
        int sign = 1;
        // 遇到左括号停止运算或者栈内没有元素

        while (st.size() && st.top() != '(')
        {
            // 处理符号
            if (st.top() == '+' || st.top() == '-')
            {
                if (st.top() == '-')
                {
                    sign = (-1) * sign;
                }
                st.pop();
                // 如果下一个字符不是加号或者减号时
                if (!st.size() || st.top() == '(' || (st.top() != '+' && st.top() != '-'))
                {
                    if (value.size())
                    {
                        ret = ret + sign * stoi(value);
                        sign = 1;
                        value.clear();
                    }
                }
            }
            else
            {
                value = st.top() + value;
                st.pop();
            }
        }
        if (value.size())
        {
            ret += stoi(value);
        }
        if (isInner)
            st.pop();
        for (auto &c : to_string(ret))
        {
            st.push(c);
        }
        return;
    }
};
// @lc code=end

