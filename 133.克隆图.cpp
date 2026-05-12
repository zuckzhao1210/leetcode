// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem133.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    std::unordered_map<Node*, Node*> nodesmap;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* cur_node =  new Node(node->val);
        Node* ans = cur_node;
        nodesmap[node] = cur_node;
        dfs(node);
        return ans;
    }

    void dfs(Node* node) {
        if (!node->neighbors.empty()) {
            for (auto neighbor : node->neighbors) {
                if (!nodesmap.contains(neighbor)) {
                    Node* new_node = new Node(neighbor->val);
                    nodesmap[neighbor] = new_node;
                    dfs(neighbor);
                }
                nodesmap[node]->neighbors.push_back(nodesmap[neighbor]);
            }
        }
        return;
    }
};
// @lc code=end

