#include "lc_tree.h"
#include <vector>

class Solution {
  public:
    std::vector<int> flipMatchVoyage(TreeNode *root, std::vector<int> &voyage) {
        std::vector<int> res;
        int idx = 0;
        dfs(root, idx, voyage.size(), res, voyage);
        if (!res.empty() && res[0] == -1) {
            res.clear();
            res.push_back(-1);
        }
        return res;
    }

    void dfs(TreeNode *root, int &idx, int n, std::vector<int> &res, const std::vector<int> &voyage) {
        if (!root) return;
        if (root->val != voyage[idx++]) {
            res.clear();
            res.push_back(-1);
            return;
        }

        if (idx < n && root->left && root->left->val != voyage[idx]) {
            res.push_back(root->val);
            dfs(root->right, idx, n, res, voyage);
            dfs(root->left, idx, n, res, voyage);
            return;
        }
        dfs(root->left, idx, n, res, voyage);
        dfs(root->right, idx, n, res, voyage);
    }
};
