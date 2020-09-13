#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode * next;
    ListNode(int x) : val(x), next(nullptr){};
};

class Solution {
    public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode * new_head = new ListNode(0);
        ListNode * pre = new_head;
        ListNode * cur = pHead;
        while(cur != nullptr) {
            while(cur != nullptr && cur->next != nullptr && cur->val == cur->next->val) {
                while(cur->next != nullptr && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
            }
            // if(cur == nullptr) {
            //     pre->next =cur;
            //     pre = cur;
            // }
            // val !=
            if(cur != nullptr) {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        pre->next = nullptr;
        return new_head->next;
    }
};



int main() {
    vector<int> v({1,2,3,3,4,4,5});
    ListNode * head = new ListNode(0);
    ListNode * node = head;
    for(auto i : v) {
        node->next = new ListNode(i);
        node = node->next;
    }
    node->next = nullptr;
    // while(head != nullptr) {
    //     cout << head->val;
    //     head = head->next;
    // }
    Solution s;
    ListNode * ans = s.deleteDuplication(head->next);
    while(ans != nullptr) {
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}
