#include "lc_tree.h"

class Solution {
  public:
    int maxDepth(Node *root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (auto child : root->children) depth = std::max(depth, maxDepth(child));
        return depth + 1;
    }
};
