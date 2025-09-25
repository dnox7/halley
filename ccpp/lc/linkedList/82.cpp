#include "lc_ll.h"

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        ListNode *dum = new ListNode(-1, curr);
        ListNode *prev = dum;

        while (curr) {
            while (curr->next && curr->val == curr->next->val) curr = curr->next;
            if (prev->next == curr) prev = prev->next;
            else prev->next = curr->next;
            curr = curr->next;
        }
        return dum->next;
    }
};
