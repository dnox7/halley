#include "lc_tree.h"

class Solution {
  public:
    TreeNode *convertBST(TreeNode *root) {
        int prev = 0;
        solve(root, prev);
        return root;
    }

    void solve(TreeNode *root, int &prev) {
        if (!root) return;
        solve(root->right, prev);
        root->val += prev;
        prev = root->val;
        solve(root->left, prev);
    }
};
