// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* cur = root;
        if (!cur) {
            return cur;
        }

        TreeNode* temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
        invertTree(cur->left);
        invertTree(cur->right);
        return root;
    }

};
// @lc code=end

