#include "lc_tree.h"

class Solution {
  public:
    int longestUnivaluePath(TreeNode *root) {
        int res = 0;
        solve(root, -1, res);
        return res;
    }

    int solve(TreeNode *root, int prev, int &res) {
        if (!root) return 0;
        int left = solve(root->left, root->val, res);
        int right = solve(root->right, root->val, res);
        res = std::max(res, left + right);
        return root->val == prev ? std::max(left, right) + 1 : 0;
    }
};
