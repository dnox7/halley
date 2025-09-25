#include "lc_tree.h"

class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        solve(root, val);
        return root;
    }

    void solve(TreeNode *root, int key) {
        if (root->val < key) {
            if (!root->right) root->right = new TreeNode(key);
            else solve(root->right, key);
            return;
        }

        if (!root->left) root->left = new TreeNode(key);
        else solve(root->left, key);
    }
};
