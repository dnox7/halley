#include "lc_tree.h"
#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<std::string, std::pair<int, TreeNode *>> freq;

  public:
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        std::vector<TreeNode *> res;
        dfs(root);
        for (const auto &[preorder, p] : freq) {
            if (p.first > 1) res.push_back(p.second);
        }
        return res;
    }

    std::string dfs(TreeNode *root) {
        if (!root) return "";
        std::string preorder = std::to_string(root->val);
        preorder += "," + dfs(root->left);
        preorder += "," + dfs(root->right);
        if (freq.count(preorder) == 0) freq[preorder] = std::make_pair(1, root);
        else freq[preorder].first++;
        return preorder;
    }
};
