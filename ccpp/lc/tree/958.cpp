#include "lc_tree.h"
#include <queue>

class Solution {
  public:
    bool isCompleteTree(TreeNode *root) {
        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});

        int prevIdx = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [curr, idx] = q.front();
                q.pop();

                if (idx - prevIdx > 1) return false;
                prevIdx = idx;

                if (curr->left) q.push({curr->left, 2 * idx + 1});
                if (curr->right) q.push({curr->right, 2 * idx + 2});
            }
        }
        return true;
    }
};
