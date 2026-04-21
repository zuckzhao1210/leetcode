// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return isChildSymmetric(root->left, root->right);
    }

    // 叶子节点是否对称
    bool isChildSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) 
            return true;

        if (left && right) {
            return (left->val == right->val) 
                    && isChildSymmetric(left->left, right->right) 
                    && isChildSymmetric(left->right, right->left);
        }
        return false;
    }
};
// @lc code=end

