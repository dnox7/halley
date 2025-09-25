#include "lc_tree.h"

class Solution {
  private:
    std::pair<int, int> dfs(TreeNode *root, int &res) {
        if (!root) return {0, 0};
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        int total = root->val + left.first + right.first;
        int treeSize = 1 + left.second + right.second;
        if (root->val == total / treeSize) res++;
        return {total, treeSize};
    }

  public:
    int averageOfSubtree(TreeNode *root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
