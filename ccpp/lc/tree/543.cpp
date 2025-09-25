#include "lc_tree.h"

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }

    int maxDepth(TreeNode *root, int &res) {
        if (!root) return 0;
        int left = maxDepth(root->left, res);
        int right = maxDepth(root->right, res);
        res = std::max(res, left + right);
        return std::max(left, right) + 1;
    }
};
