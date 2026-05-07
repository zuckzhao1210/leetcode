// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

/** 
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        std::unordered_map<ListNode*, ListNode*> premap;
        ListNode* cur = head;
        int len = 1;
        while (cur && cur->next) {
            ++len;
            premap[cur->next] = cur;
            cur = cur->next;
        }
        premap[head] = cur;

        int m = k % len;

        for (int i = 0; i < m; ++i) {
            cur->next = head;
            head = cur;
            ListNode* prev = premap[cur];
            prev->next = nullptr;
            cur = prev;
        }
        return head;
    }
*/
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        
        // 计数
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        int n = k % len;
        ListNode* fast = head;
        ListNode* slow = head;
        // 快指针前进
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }


};
// @lc code=end

