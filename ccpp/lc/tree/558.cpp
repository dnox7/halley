#include "lc_tree.h"

#define Node QuadTreeNode

class Solution {
  public:
    Node *intersect(Node *quadTree1, Node *quadTree2) {
        if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;

        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tl->val == bl->val && tl->val == br->val) {
            return new Node(tl->val, true);
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};
