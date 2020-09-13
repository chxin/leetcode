/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.90%)
 * Total Accepted:    92.3K
 * Total Submissions: 141.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例:
 *
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        return recursion(head, head->next);
    }

    ListNode * recursion(ListNode * node1, ListNode * node2) {
        if(node1 == nullptr || node2 == nullptr) {
            return node1;
        }
        if(node2->next != nullptr) {
            node1->next = recursion(node2->next, node2->next->next);
        } else {
            node1->next = nullptr;
        }
        node2->next = node1;
        return node2;

    }
};
