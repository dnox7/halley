#include "lc_tree.h"
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
  public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        std::vector<long long> totals;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long long s = 0;
            while (n--) {
                TreeNode *curr = q.front();
                q.pop();
                s += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            totals.push_back(s);
        }

        if (totals.size() < k) return -1;
        std::sort(totals.begin(), totals.end(), std::greater<>());
        return totals[k - 1];
    }
};
