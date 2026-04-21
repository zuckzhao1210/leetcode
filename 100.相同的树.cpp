// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem100.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    std::queue<TreeNode*> queue_p;
    std::queue<TreeNode*> queue_q;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q && (p->val == q->val)) {
            queue_p.push(p);
            queue_q.push(q);
        }
        else {
            if (!p && !q) {
                return true;
            } else {
                return false;
            }
        }

        while (!queue_p.empty() && !queue_q.empty()) {
            TreeNode* cur_p = queue_p.front();
            queue_p.pop();
            TreeNode* cur_q = queue_q.front();
            queue_q.pop();
            // 对比左右节点；
            if ((cur_p->left && cur_q->left && cur_p->left->val == cur_q->left->val)
                || (!cur_p->left && !cur_q->left)) {
                if (cur_p->left) {
                    queue_p.push(cur_p->left);
                    queue_q.push(cur_q->left);
                }
            }
            else {
                return false;
            }
            if ((cur_p->right && cur_q->right && cur_p->right->val == cur_q->right->val)
                || (!cur_p->right && !cur_q->right)) {
                if (cur_p->right) {
                    queue_p.push(cur_p->right);
                    queue_q.push(cur_q->right);
                }
            }
            else {
                return false;
            }
        }
        return true;
    }

};
// @lc code=end

