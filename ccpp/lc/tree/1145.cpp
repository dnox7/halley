#include "lc_tree.h"

class Solution {
    int left, right;

  public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        count(root, x);
        return std::max(std::max(left, right), n - left - right - 1) > n / 2;
    }

    int count(TreeNode *root, int x) {
        if (!root) return 0;
        int lc = count(root->left, x);
        int rc = count(root->right, x);
        if (root->val == x) left = lc, right = rc;
        return lc + rc + 1;
    }
};
