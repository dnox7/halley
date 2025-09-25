#include "lc_ll.h"

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        while (curr) {
            while (curr->next) {
                if (curr->val == curr->next->val) curr->next = curr->next->next;
                else break;
            }
            curr = curr->next;
        }
        return head;
    }
};
