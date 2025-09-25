#include "lc_ll.h"
#include <stack>

class Solution {
  public:
    void reorderList(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow->next;
        std::stack<ListNode *> s;
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }

        curr = head;
        while (!s.empty()) {
            ListNode *next = curr->next;
            ListNode *node = s.top();
            s.pop();
            node->next = next;
            curr->next = node;
            curr = next;
        }
        curr->next = nullptr;
    }
};
