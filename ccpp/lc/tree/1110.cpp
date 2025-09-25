#include "lc_tree.h"
#include <unordered_set>

class Solution {
  public:
    std::vector<TreeNode *> delNodes(TreeNode *root, std::vector<int> &toDelete) {
        std::vector<TreeNode *> res;
        std::unordered_set<int> s(toDelete.begin(), toDelete.end());
        root = solve(root, s, res);
        if (root) res.push_back(root);
        return res;
    }

    TreeNode *solve(TreeNode *root, const std::unordered_set<int> &s, std::vector<TreeNode *> &res) {
        if (!root) return root;
        root->left = solve(root->left, s, res);
        root->right = solve(root->right, s, res);
        if (s.count(root->val)) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
};
