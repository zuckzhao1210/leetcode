// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem129.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        std::stack<TreeNode*> st;
        int ans = 0;
        int sum = 0;
        std::unordered_map<TreeNode*, int> nodeTosum;
        st.push(root);
        nodeTosum[root] = 0;
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            sum = nodeTosum[cur];
            sum = sum * 10 + cur->val;
            if (cur->left) {
                st.push(cur->left);
                nodeTosum[cur->left] = sum;
            }
            if (cur->right) {
                st.push(cur->right);
                nodeTosum[cur->right] = sum;
            }
            if (!cur->left && !cur->right) {
                ans += sum;
            }
        }

        return ans;
    }
};
// @lc code=end

