// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.emplace(root);
        while(q.size())
        {
            int sz = q.size();
            ret.emplace_back(0);
            while(sz--)
            {
                TreeNode* t = q.front();
                q.pop();
                ret.back().emplace_back(t->val);
                if(t->left) q.emplace(t->left);
                if(t->right) q.emplace(t->right);
            }
        }
        for(int i =1;i<ret.size();i+=2)
        reverse(ret[i].begin(),ret[i].end());
        return ret;
    }
};



