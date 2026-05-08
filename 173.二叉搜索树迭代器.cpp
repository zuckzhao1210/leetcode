// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem173.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:

    std::vector<int> vec;
    int index;

    BSTIterator(TreeNode* root) {
        index = 0;
        vec.push_back(-1);
        this->midorder(root);
    }

    void midorder(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) {
            this->midorder(root->left);
        }
        vec.push_back(root->val);
        if (root->right) {
            this->midorder(root->right);
        }
        return;
    }
    
    int next() {
        ++index;
        return vec[index];
    }
    
    bool hasNext() {
        if (index < vec.size() - 1) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

