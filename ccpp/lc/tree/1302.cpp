#include "lc_tree.h"
#include <queue>

class Solution {
  public:
    int deepestLeavesSum(TreeNode *root) {
        std::queue<TreeNode *> q;
        int res = 0;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            res = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                res += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};
