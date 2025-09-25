#include "lc_tree.h"
#include <climits>
#include <queue>

class Solution {
  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        if (!root || !root->left && !root->right) return root;
        TreeNode *leftMost = nullptr, *rightMost = nullptr;

        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (i == 0) leftMost = curr;
                if (i == n - 1) rightMost = curr;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return lca(root, leftMost, rightMost);
    }

    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
