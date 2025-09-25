#include "lc_tree.h"
#include <queue>

class Solution {
  public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        std::queue<std::vector<TreeNode *>> q;
        q.push({root});

        int level = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int n = curr.size();
            std::vector<TreeNode *> children;
            for (int i = 0; i < n; ++i) {
                if (i < n / 2 && level % 2 == 1) std::swap(curr[i]->val, curr[n - 1 - i]->val);
                if (curr[i]->left) children.push_back(curr[i]->left);
                if (curr[i]->right) children.push_back(curr[i]->right);
            }
            level++;
            if (children.size() != 0) q.push(children);
        }
        return root;
    }
};
