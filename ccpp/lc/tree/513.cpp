#include "lc_tree.h"
#include <climits>

class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) {
        int res = 0, maxDepth = INT_MIN;
        solve(root, 0, maxDepth, res);
        return res;
    }

    void solve(TreeNode *root, int currDepth, int &maxDepth, int &res) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (currDepth > maxDepth) {
                maxDepth = currDepth;
                res = root->val;
            }
        }
        solve(root->left, currDepth + 1, maxDepth, res);
        solve(root->right, currDepth + 1, maxDepth, res);
    }
};
