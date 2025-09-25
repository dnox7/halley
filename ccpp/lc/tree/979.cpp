#include "lc_tree.h"

class Solution {
  public:
    int distributeCoins(TreeNode *root) {
        int res = 0;
        solve(root, res);
        return res;
    }

    int solve(TreeNode *root, int &res) {
        if (!root) return 0;
        root->val += solve(root->left, res);
        root->val += solve(root->right, res);
        if (root->val > 1) res += root->val - 1;
        else if (root->val < 1) res += 1 - root->val;
        return root->val - 1;
    }
};
