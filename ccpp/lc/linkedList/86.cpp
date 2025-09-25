#include "lc_ll.h"
#include <queue>

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *d1 = new ListNode(-1), *d2 = new ListNode(-1);
        ListNode *q1 = d1, *q2 = d2, *curr = head;

        while (curr) {
            if (curr->val < x) {
                q1->next = curr;
                q1 = q1->next;
            } else {
                q2->next = curr;
                q2 = q2->next;
            }
            curr = curr->next;
        }

        q1->next = d2->next;
        q2->next = nullptr;
        return d1->next;
    }
};

class Solution1 {
  public:
    ListNode *partition(ListNode *head, int x) {
        std::queue<ListNode *> q1;
        std::queue<ListNode *> q2;

        ListNode *curr = head;
        while (curr) {
            if (curr->val < x) q1.push(curr);
            else q2.push(curr);
            curr = curr->next;
        }

        ListNode *dummy = new ListNode(-1);
        curr = dummy;
        while (!q1.empty()) {
            ListNode *node = q1.front();
            q1.pop();
            curr->next = node;
            curr = curr->next;
        }

        while (!q2.empty()) {
            ListNode *node = q2.front();
            q2.pop();
            curr->next = node;
            curr = curr->next;
        }

        curr->next = nullptr;
        return dummy->next;
    }
};
