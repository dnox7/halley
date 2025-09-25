#include "lc_tree.h"

class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        int res = 0;
        traverse(root, k, res);
        return res;
    }

    void traverse(TreeNode *root, int &k, int &res) {
        if (!root) return;
        traverse(root->left, k, res);
        if (k == 1) res = root->val;
        k--;
        traverse(root->right, k, res);
    }
};
