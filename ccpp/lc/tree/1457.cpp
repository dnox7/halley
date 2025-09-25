#include "lc_tree.h"

class Solution {
  public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, int bs, int &res) {
        if (!root) return;
        bs ^= 1 << root->val;
        if (!root->left && !root->right) {
            if ((bs > 0 && (bs & (bs - 1)) == 0) || bs == 0) {
                res++;
                return;
            }
        }
        dfs(root->left, bs, res);
        dfs(root->right, bs, res);
    }
};
