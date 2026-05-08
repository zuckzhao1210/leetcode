// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* cur = root;

        // 1.最底层左节点确定高度
        int depth = 0;
        while (cur) {
            ++depth;
            cur = cur->left;
        }
        cur = root;
        // 2. 寻找最底层最右侧节点
        int num = pow(2, depth) - 1;
        std::stack<TreeNode*> st;
        while (st.size() < depth && cur) {
            st.push(cur);
            cur = cur->right;
        }

        if (st.size() == depth) return num;
        
        while (!cur) {
            --num;
            // 左叶子节点
            if (num % 2 == 1) {
                TreeNode* father = st.top();
                st.pop();
                while (father == st.top()->left) {
                    father = st.top();
                    st.pop();
                }
                st.push(st.top()->left);
                while (st.top()->right) {
                    st.push(st.top()->right);
                }
                if (st.size() == depth) {
                    return num;
                } else {
                    cur = st.top()->right;
                }
            } 
            // 右叶子节点
            else {
                cur = st.top()->left;
            }
        }
        return num;
    }
};
// @lc code=end

