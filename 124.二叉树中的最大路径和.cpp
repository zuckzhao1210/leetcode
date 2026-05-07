// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem124.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        int maxpath = root->val;
        auto temp = maxBranchs(root, maxpath);
        return maxpath;
    }

    std::pair<int, int> maxBranchs(TreeNode* root, int& maxpath) {
        if (!root->left && !root->right) {
            maxpath = std::max(maxpath, root->val);
            return {root->val, root->val};
        }
         
        int leftBranch = root->val;
        int rightBranch = root->val;
        if (root->left) {
            auto l1 = maxBranchs(root->left, maxpath);
            int l1_max = std::max(l1.first, l1.second);
            if (l1_max > 0) {
                leftBranch = root->val + l1_max;
            }
        }

        if (root->right) {
            auto l2 = maxBranchs(root->right, maxpath);
            int l2_max = std::max(l2.first, l2.second);
            if (l2_max > 0) {
                rightBranch = root->val + l2_max;
            }
        }

        maxpath = std::max(maxpath, leftBranch + rightBranch - root->val);
        return {leftBranch, rightBranch};
    }
};
// @lc code=end

