#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    // case: null, 1, head dup,
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // node, pre_node = node, next_node
        // all equal node: while(next_node->val == node->val)
        if(pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode * result = pHead;
        ListNode * pre_node = nullptr;
        ListNode * node = pHead;
        int flag = 0;
        while(node != nullptr) {
            while(node != nullptr && node->next != nullptr && node->val == node->next->val) {
                int d_value = node->val;
                while(node != nullptr && node->val == d_value) {
                    node = node->next;
                }
                // node = node->next;
            }

            if(flag == 0) {
                result = node;
                flag = 1;
                pre_node = result;
            } else {
                pre_node->next = node;
                pre_node = node;
            }


            node = node->next;
        }
        return result;
    }
};


int main() {
    ListNode * head = new ListNode(1);
    ListNode * node = head;
    vector<int>input = {2, 3, 3, 4, 4, 5};
    for(auto i : input) {
        node->next = new ListNode(i);
        node = node->next;
    }

    Solution s;
    ListNode * result = s.deleteDuplication(head);

    while(result != nullptr) {
        cout << result->val;
        result = result->next;
    }

    return 0;
}
