#include "lc_tree.h"
#include <algorithm>

class Solution {
  public:
    int goodNodes(TreeNode *root) {
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, int maxNode, int &res) {
        if (!root) return;
        if (root->val >= maxNode) res++;
        dfs(root->left, std::max(root->val, maxNode), res);
        dfs(root->right, std::max(root->val, maxNode), res);
    }
};
