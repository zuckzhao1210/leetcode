// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem230.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        midorder(root, &order);
        return order[k - 1];
    }

    void midorder(TreeNode* node, vector<int>* order) {
        if (!node) {
            return;
        }
        midorder(node->left, order);
        order->push_back(node->val);
        midorder(node->right, order);
        return;
    }
};
// @lc code=end

