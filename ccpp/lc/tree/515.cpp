#include "lc_tree.h"
#include <climits>
#include <queue>

class Solution {
  public:
    std::vector<int> largestValues(TreeNode *root) {
        std::vector<int> res;
        if (!root) return res;
        std::queue<TreeNode *> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxNode = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                maxNode = std::max(maxNode, curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(maxNode);
        }
        return res;
    }
};
