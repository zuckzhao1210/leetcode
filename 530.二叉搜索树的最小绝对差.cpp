// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> order;
        midorder(root, &order);
        int ans = order[1] - order[0];
        for (int i = 1; i < order.size(); ++i) {
            int dis = order[i] - order[i - 1];
            ans = min(dis, ans);
        }
        return ans;
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

