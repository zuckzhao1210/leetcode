// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem106.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> map; 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, int inleft, int inright, vector<int>& postorder, int postleft, int postright) {
        int val = postorder[postright];
        int inorder_index = map[val];
        TreeNode* node = new TreeNode(val);
        if (inorder_index != inleft) {
            int left_node_num = inorder_index - inleft;
            node->left = build(inorder, inleft, inorder_index - 1, postorder, postleft, postleft + left_node_num - 1);
        }
        if (inorder_index != inright) {
            int right_node_num = inright - inorder_index;
            node->right = build(inorder, inorder_index + 1, inright, postorder, postright - right_node_num, postright - 1);
        }
        return node;
    }
};
// @lc code=end

