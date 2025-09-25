#include "lc_tree.h"
#include <cstdlib>

class Solution {
  public:
    int maxAncestorDiff(TreeNode *root) {
        int res = 0;
        solve(root, res);
        return res;
    }

    std::pair<int, int> solve(TreeNode *root, int &res) {
        int maxCurr = root->val, minCurr = root->val;
        if (!root->left && !root->right) return {maxCurr, minCurr};

        if (root->left) {
            auto [maxLeft, minLeft] = solve(root->left, res);
            maxCurr = std::max(maxCurr, maxLeft);
            minCurr = std::min(minCurr, minLeft);
            int k = std::max(std::abs(root->val - maxLeft), std::abs(root->val - minLeft));
            res = std::max(res, k);
        }

        if (root->right) {
            auto [maxRight, minRight] = solve(root->right, res);
            maxCurr = std::max(maxCurr, maxRight);
            minCurr = std::min(minCurr, minRight);
            int k = std::max(std::abs(root->val - maxRight), std::abs(root->val - minRight));
            res = std::max(res, k);
        }
        return {maxCurr, minCurr};
    }
};
