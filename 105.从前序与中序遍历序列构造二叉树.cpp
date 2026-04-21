// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int val = preorder[0];
        int index = -1;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == val) {
                index = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(val);
        if (index != 0) {
            vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + index + 1);
            vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
            root->left = buildTree(left_preorder, left_inorder);
        }

        if (index != inorder.size() - 1) {
            vector<int> right_preorder(preorder.begin() + index + 1, preorder.end());
            vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
            root->right = buildTree(right_preorder, right_inorder);
        }

        return root;
    }
};
// @lc code=end

