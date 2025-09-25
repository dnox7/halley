#include "lc_tree.h"

class Solution {
  public:
    int rob(TreeNode *root) {
        auto res = solve(root);
        return std::max(res.first, res.second);
    }

    std::pair<int, int> solve(TreeNode *root) {
        if (!root) return {};
        auto left = solve(root->left);
        auto right = solve(root->right);
        return {std::max(left.first, left.second) + std::max(right.first, right.second), root->val + left.first + right.first};
    }
};
