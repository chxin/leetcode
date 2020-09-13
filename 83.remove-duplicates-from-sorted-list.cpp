/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.66%)
 * Total Accepted:    87.9K
 * Total Submissions: 176.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 示例 1:
 *
 * 输入: 1->1->2
 * 输出: 1->2
 *
 *
 * 示例 2:
 *
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> value_map;
        ListNode * node = head;
        if(node != nullptr)
            value_map[node->val]++;
        else
            return head;
        while(node->next != nullptr) {
            int value = node->next->val;
            value_map[value]++;
            if(value_map[value] > 1) {
                ListNode * tmp = node->next;
                node->next = tmp->next;
                delete tmp;
                tmp = nullptr;
            } else {
                node = node->next;
            }
            if(node == nullptr) break;
        }
        return head;
    }
};
