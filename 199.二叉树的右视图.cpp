// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <deque>
#include "commoncppproblem199.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; 
        std::deque<TreeNode*> de;
        de.push_back(root);
        TreeNode* rightest;
        rightest = root;
        while (!de.empty()) {
            TreeNode* cur = de.front();
            de.pop_front();
            if (cur->left) {
                de.push_back(cur->left);
            }
            if (cur->right) {
                de.push_back(cur->right);
            }
            // 上一层的最右侧节点
            if (cur == rightest) {
                ans.push_back(cur->val);
                if (!de.empty())
                    rightest = de.back();
            }
        }

        return ans;
    }
};
// @lc code=end

