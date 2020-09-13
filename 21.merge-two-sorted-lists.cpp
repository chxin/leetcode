/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (60.50%)
 * Total Accepted:    219.8K
 * Total Submissions: 361.7K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 * 示例：
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return FirstLink(l1, l2);
        return l1;
    }

    ListNode * FirstLink(ListNode * l1, ListNode * l2) {
        ListNode * l1_old;
        ListNode * head;

        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        l1_old = head;

        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                l1_old->next = l1;
                l1_old = l1_old->next;
                l1 = l1->next;
            } else {
                l1_old->next = l2;
                l1_old = l1_old->next;
                l2 = l2->next;
            }
        }

        if(l1 == nullptr) {
            l1_old->next = l2;
        }
        if(l2 == nullptr) {
            l1_old->next = l1;
        }
        return head;
    }

    void Head(ListNode * l1, ListNode * l2) {
        ListNode * l1_old;
        ListNode * head;

        if(l1 == l2) return;
        if(l1 == nullptr) {
            l1 = l2;
            return;
        }
        if(l2 == nullptr) return;
        if(l1->val < l2->val) {
            l1_old = l1;
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l1_old = l2;
            ListNode * tmp = l2->next;
            l2->next = l1;
            l2 = tmp;
        }
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                l1_old = l1;
                l1 = l1->next;
            } else {
                ListNode * tmp = l2->next;
                l1_old->next = l2;
                l1_old = l2;
                l2->next = l1;
                l2 = tmp;
            }
        }

        if(l1 == nullptr) {
            l1_old->next = l2;
        }

        l1 = head;
    }


    ListNode * newLists(ListNode * l1, ListNode * l2) {
                ListNode * head = nullptr;
        if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        } else {
            if(l1->val < l2->val) {
                head = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head = new ListNode(l2->val);
                l2 = l2->next;
            }
        }

        ListNode * node = head;

        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                ListNode * tmp = new ListNode(l1->val);
                node->next = tmp;
                node = tmp;
                l1 = l1->next;
            } else {
                ListNode * tmp = new ListNode(l2->val);
                node->next = tmp;
                node = tmp;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr) {
            node->next = l1;
        } else if(l2 != nullptr) {
            node->next = l2;
        } else {
            head = nullptr;
        }

        return head;

    }
};

// int main(void) {
//     Solution ins;
//     ListNode * l1 = new ListNode(1);
//     l1->next = new ListNode(2);
//     l1->next->next = new ListNode(4);

//     ListNode * l2 = new ListNode(1);
//     l2->next = new ListNode(3);
//     l2->next->next = new ListNode(4);

//     l1 = ins.mergeTwoLists(l1, l2);

//     cout << "end" << endl;
//     while(l1 != nullptr) {
//         cout << l1->val << " ";
//         l1 = l1->next;
//     }

//     return 0;
// }
