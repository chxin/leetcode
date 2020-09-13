/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (41.03%)
 * Total Accepted:    79.3K
 * Total Submissions: 191.6K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 *
 * 示例 1:
 *
 * 输入: 1->2
 * 输出: false
 *
 * 示例 2:
 *
 * 输入: 1->2->2->1
 * 输出: true
 *
 *
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        ListNode * node = head;
        int size = 0;
        while(node != nullptr) {
            node = node->next;
            ++size;
        }
        if(size <= 1) return 1;
        node = head;
        int mid = (size + 1) / 2;
        while(mid--) {
            node = node->next;
        }
        ListNode * node_pre = nullptr;
        ListNode * reverse_node = node;
        ListNode * node_next = node->next;
        reverse_node->next = node_pre;
        while(node_next != nullptr) {
            // cout << reverse_node->val;
            reverse_node->next = node_pre;
            node_pre = reverse_node;
            reverse_node = node_next;
            node_next = node_next->next;
        }
        reverse_node->next = node_pre;
        ListNode * node_right = reverse_node;
        ListNode * node_left = head;
        while(node_right != nullptr && node_left->val == node_right->val) {
            // cout << node_right->val;
            node_left = node_left->next;
            node_right = node_right->next;
        }
        // if(node_left == node || (node_right == nullptr && node == node_left->next))
        if(node_right == nullptr)
            return 1;
        else
            return 0;
    }
};
