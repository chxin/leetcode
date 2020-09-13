/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (54.63%)
 * Total Accepted:    28.3K
 * Total Submissions: 49.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 *
 *
 * 进阶：
 *
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 *
 *
 *
 * 示例：
 *
 * 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l1_node = l1;
        ListNode * l2_node = l2;
        ListNode * end_node = new ListNode(-1);
        ListNode * head = end_node;
        int flag1 = 0;
        int flag2 = 0;
        int carrier = 0;
        while(1) {
            if(l1_node == nullptr) {
                flag1 =1;
                l1_node = l2;
            }
            if(l2_node == nullptr) {
                flag2 =1;
                l2_node = l1;
            }
            if(flag1 == 1 || flag2 == 1) {
                carrier = recursion(l1_node, l2_node, end_node, flag1, flag2, l1, l2);
                break;
            }
            l1_node = l1_node->next;
            l2_node = l2_node->next;

        }
        if(carrier == 1){
            ListNode * tmp = new ListNode(1);
            tmp->next = head;
            return tmp;
        }
        return head;
    }

    int recursion(ListNode * l1, ListNode * l2, ListNode * node, int flag1, int flag2, ListNode * l1_head, ListNode * l2_head) {
        int carrier = 0;
        if(l1 == nullptr && l2 == nullptr) {
            return 0;
        }
        if(l1 == nullptr) {
            flag1 = 1;
            l1 = l2_head;
        }
        if(l2 == nullptr) {
            flag2 = 1;
            l2 = l1_head;
        }

        if(flag1 == 1 || flag2 == 1) {
            int a1 = flag1? l1->val : 0;
            int a2 = flag2? l2->val : 0;
            int sum = 0;
            if(l1->next != nullptr || l2->next != nullptr) {
                node->next = new ListNode(0);
                sum = a1 + a2 + recursion(l1->next, l2->next, node->next, flag1, flag2, l1_head, l2_head);
            } else {
                sum = a1 + a2;
            }
            if(sum > 9) {
                sum -= 10;
                carrier = 1;
            } else {
                carrier = 0;
            }
            node->val = sum;
        } else {
            // recursion(l1->next, l2->next, node, flag1, flag2, l1_head, l2_head);
        }
        return carrier;
    }
};
