// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem236.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        auto lans = dfs(root->left, p, q);
        auto rans = dfs(root->right, p, q);
        // 左侧有，右侧也有  或者  根节点就是其中一个且左侧或者右侧有一个
        if ((lans && rans) || ((root == p || root == q) && (lans || rans))) {
            ans = root;
        }

        if (lans || rans || root == p || root == q) {
            return true;
        }
        return false;
    }
};
// @lc code=end

