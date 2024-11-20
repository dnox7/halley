#include "common_ds.h"
#include <unordered_set>

class Solution {
  public:
    ListNode *getIntersectionNode1(ListNode *h1, ListNode *h2) {
        if (!h1 || !h2) return nullptr;
        ListNode *c1 = h1;
        ListNode *c2 = h2;
        while (c1 != c2) {
            c1 = !c1 ? h2 : c1->next;
            c2 = !c2 ? h1 : c2->next;
        }
        return c1;
    }

    ListNode *getIntersectionNode2(ListNode *h1, ListNode *h2) {
        std::unordered_set<ListNode *> s;
        for (auto c = h1; c != nullptr; c = c->next) s.insert(c);
        for (auto c = h2; c != nullptr; c = c->next)
            if (s.count(c)) return c;
        return nullptr;
    }
};
