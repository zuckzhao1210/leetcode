// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem82.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-999);
        dummy->next = head;
        ListNode* prev = dummy;
        while (prev->next) {
            prev = deleteRepeat(prev);
        }
        return dummy->next;
    }


    ListNode* deleteRepeat(ListNode* prev) {
        ListNode* cur = prev->next;
        bool del = false;
        while (cur) {
            // 没有下一个节点或者下一个节点的值不同
            if (!cur->next || cur->next->val != cur->val) {
                if (del) {
                    prev->next = cur->next;
                }
                else {
                    prev = cur;
                }
                break;
            }
            else {
                del = true;
                cur = cur->next;
            }
        }
        return prev;
    }
*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = new ListNode(0);
        ListNode* ans = cur;
        while (head) {
            int k = head->val;
            // if (head->next == nullptr) {
            //     cur->next = head;
            //     break;
            // }
            if (head->next==nullptr || head->next->val != k) {
                cur->next = head;
                cur = cur->next;
                head = head->next;
            } else {
                while (head && head->val == k) {
                    head = head->next;
                }
            }
        }
        cur->next=nullptr;
        return ans->next;
    }
};
// @lc code=end

