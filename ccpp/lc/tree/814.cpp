#include "lc_tree.h"

class Solution {
  public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!root) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val != 1) return nullptr;
        return root;
    }
};
