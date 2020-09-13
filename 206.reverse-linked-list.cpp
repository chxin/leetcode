/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.18%)
 * Total Accepted:    212.4K
 * Total Submissions: 310.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 *
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
// #include <iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * result = head;
        // recursion(head->next, head, result);
        iteration(head);
        // head->next = nullptr;
        return head;
    }

    void recursion(ListNode * & node, ListNode * & pre_node, ListNode * & reversed_head) {
        if(node == nullptr) {
            reversed_head = pre_node;
            return;
        }
        recursion(node->next, node, reversed_head);
        node->next = pre_node;
    }
    void iteration(ListNode * & node) {
        ListNode * next_node = node->next;
        ListNode * tmp_node = nullptr;
        while(node->next != nullptr) {
            node->next = tmp_node;
            tmp_node = node;
            node = next_node;
            next_node = next_node->next;
        }
        node->next = tmp_node;
        // return node;
    }
};

// int main(void) {
//     Solution ins;
//     ListNode * head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);

//     ListNode * node = ins.reverseList(head);
//     while(node != nullptr) {
//         cout << node->val;
//         node = node->next;
//     }

//     return 0;
// }
