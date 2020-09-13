/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.87%)
 * Total Accepted:    106.9K
 * Total Submissions: 289.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和
 * n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 *
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 *
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * next_node = head;
        ListNode * tmp_node = head;
        // while(n-- && next_node != nullptr) {
        //     next_node = head->next;
        // }
        if(n == 0 || head == nullptr) return head;
        int i = 0; // total count
        while(next_node != nullptr) {
            next_node = next_node->next;
            if(i > n)
                tmp_node = tmp_node->next;
            ++i;
        }
        if(i < n) {

        } else if(i == n) {
            ListNode * tmp_head = head;
            head = head->next;
            delete tmp_head;
            tmp_head = nullptr;
        } else {
            ListNode * tmp = tmp_node->next;
            tmp_node->next = tmp->next;
            delete tmp;
            tmp = nullptr;
        }

        return head;
    }
};
