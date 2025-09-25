#include "lc_ll.h"

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *curr = head, *prev = nullptr, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
