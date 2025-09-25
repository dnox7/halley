#include "lc_tree.h"
#include <unordered_map>

class Solution {
  public:
    int pathSum(TreeNode *root, int targetSum) {
        std::unordered_map<long long, int> m;
        m[0] = 1;
        int res = 0;
        solve(root, 0, res, static_cast<long long>(targetSum), m);
        return res;
    }

    void solve(TreeNode *root, long long curr, int &res, long long target, std::unordered_map<long long, int> &m) {
        if (!root) return;
        curr += root->val;
        res += m[curr - target];
        m[curr]++;
        solve(root->left, curr, res, target, m);
        solve(root->right, curr, res, target, m);
        m[curr]--;
    }
};
