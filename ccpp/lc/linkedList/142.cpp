#include "lc_ll.h"

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        bool isDuplicate = false;
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) return nullptr;

        ListNode *res = head;
        while (slow) {
            if (slow == res) return res;
            slow = slow->next;
            res = res->next;
        }
        return res;
    }
};
