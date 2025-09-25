#include "lc_tree.h"
#include <climits>
#include <queue>

class Solution {
  public:
    int maxLevelSum(TreeNode *root) {
        std::queue<TreeNode *> q;
        int level = 0;
        int res = level;
        int maxSum = INT_MIN;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            level++;
            int total = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                total += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (total > maxSum) {
                maxSum = total;
                res = level;
            }
        }
        return res;
    }
};
