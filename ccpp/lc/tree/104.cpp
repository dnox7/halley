#include "lc_tree.h"

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        return root ? std::max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
