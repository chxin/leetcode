/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (49.53%)
 * Total Accepted:    93K
 * Total Submissions: 187K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode * > & lists) {
        // 2: m + n;
        // 3 : m + n + m + n + o
        // 2*(m+n) + o : 2 ^ n
        // m n;
        // n * m
        /* for(int i = 1; i < lists.size(); ++i) { */
        /*     MergeTwoLinks(lists.at(i), lists.at(i - 1)); */
        /* } */
        /* return lists.at(lists.size() - 1); */
        if(lists.empty()) return nullptr;
        recursion(lists, lists.size());
        
        return lists.at(0);
    }

    void recursion(vector<ListNode *> & v, int n) {
        if(n <= 1) return;

        for(int i = 0; i < (n + 1) / 2; ++i) {
            MergeTwoLinks(v.at(i), v.at(n - i - 1));
        }

        recursion(v, (n + 1) / 2);
    }

    void MergeTwoLinks(ListNode * & l1, ListNode * l2) {
        ListNode * l1_old;
        ListNode * head;

        if(l1 == l2) return;
        if(l2 == nullptr) return;
        if(l1 == nullptr){
            l1 = l2;
            return;
        }
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
        l1 = head;

    }


};
