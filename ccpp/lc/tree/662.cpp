#include "lc_tree.h"
#include <algorithm>
#include <climits>
#include <queue>

class Solution {
  public:
    int widthOfBinaryTree(TreeNode *root) {
        std::queue<std::pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long res = 0;
        while (!q.empty()) {
            int n = q.size();
            unsigned long long leftmostIdx, rightmostIdx;
            for (int i = 0; i < n; ++i) {
                auto p = q.front();
                q.pop();

                TreeNode *root = p.first;
                unsigned long long rootIdx = p.second;
                if (i == 0) leftmostIdx = rootIdx;
                if (i == n - 1) rightmostIdx = rootIdx;
                if (root->left) q.push({root->left, 2 * rootIdx + 1});
                if (root->right) q.push({root->right, 2 * rootIdx + 2});
            }
            res = std::max(res, rightmostIdx - leftmostIdx + 1);
        }
        return static_cast<int>(res);
    }
};
