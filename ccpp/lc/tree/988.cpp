#include "lc_tree.h"
#include <algorithm>
#include <string>

class Solution {
  public:
    std::string smallestFromLeaf(TreeNode *root) {
        std::string res;
        solve(root, "", res);
        return res;
    }

    void solve(TreeNode *root, std::string curr, std::string &res) {
        if (!root) return;
        curr.push_back(root->val + 'a');
        if (!root->left && !root->right) {
            std::reverse(curr.begin(), curr.end());
            if (res.empty()) res = curr;
            else res = std::min(res, curr);
            return;
        }
        solve(root->left, curr, res);
        solve(root->right, curr, res);
    }
};
