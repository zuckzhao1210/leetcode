// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem117.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* newhead = new Node(-1);
        Node* cur = root;
        Node* preleaf = newhead;
        while (cur) {
            if (cur->left) {
                preleaf->next = cur->left;
                preleaf = preleaf->next;
                
            }
            if (cur->right) {
                preleaf->next = cur->right;
                preleaf = preleaf->next;
                
            }

            if (!cur->next) {
                cur = newhead->next;
                newhead->next = nullptr;
                preleaf = newhead;
            } 
            else {
                cur = cur->next;
            }
        }

        return root;
    }

};
//w @lc code=end

