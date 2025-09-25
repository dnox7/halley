#include "lc_tree.h"
#include <climits>
#include <queue>

class Solution {
  public:
    bool isEvenOddTree(TreeNode *root) {
        std::queue<TreeNode *> q;
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (level % 2 == 0 && (curr->val % 2 == 0 || curr->val <= prev)) return false;
                if (level % 2 == 1 && (curr->val % 2 != 0 || curr->val >= prev)) return false;
                prev = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};
