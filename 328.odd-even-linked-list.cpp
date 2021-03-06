/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 *
 * https://leetcode-cn.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (61.75%)
 * Total Accepted:    33.6K
 * Total Submissions: 54K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 *
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 *
 * 示例 1:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 *
 *
 * 示例 2:
 *
 * 输入: 2->1->3->5->6->4->7->NULL
 * 输出: 2->3->6->7->1->5->4->NULL
 *
 * 说明:
 *
 *
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
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
// #include <iostream>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr) return head;

        ListNode * tmp = head->next;
        ListNode * node1 = head;
        ListNode * node2 = head->next;
        while(node2->next != nullptr && node2->next->next != nullptr) {
            node1->next = node2->next;
            node1 = node1->next;
            node2->next = node2->next->next;
            node2 = node2->next;
        }

        if(node2->next != nullptr) {
            node1->next = node2->next;
            node1->next->next = tmp;
            node2->next = nullptr;
        } else {
            node1->next = tmp;
            node2->next = nullptr;
        }
        return head;

    }
};

// int main(void) {
//     Solution ins;
//     ListNode * head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     ListNode * result = ins.oddEvenList(head);

//     while(result != nullptr) {
//         cout << result->val;
//         result = result->next;
//     }
//     return 0;
// }
