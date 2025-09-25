#include "lc_tree.h"
#include <queue>
#include <unordered_map>

class Solution {
  public:
    int sumEvenGrandparent(TreeNode *root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode *root, int &res) {
        if (!root) return;
        if (root->val % 2 == 0) {
            if (root->left) {
                if (root->left->left) res += root->left->left->val;
                if (root->left->right) res += root->left->right->val;
            }
            if (root->right) {
                if (root->right->left) res += root->right->left->val;
                if (root->right->right) res += root->right->right->val;
            }
        }
        dfs(root->left, res);
        dfs(root->right, res);
    }
};

class Solution1 {
  public:
    int sumEvenGrandparent(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::unordered_map<TreeNode *, TreeNode *> parent;
        int res = 0, level = 0;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            level++;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (level >= 3) res += parent[parent[curr]]->val % 2 == 0 ? curr->val : 0;

                if (curr->left) {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }

                if (curr->right) {
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        return res;
    }
};
