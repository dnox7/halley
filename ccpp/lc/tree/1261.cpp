#include "lc_tree.h"
#include <queue>
#include <unordered_set>

class FindElements {
    std::unordered_set<int> s;

  public:
    FindElements(TreeNode *root) {
        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [curr, idx] = q.front();
                q.pop();
                curr->val = idx;
                s.insert(idx);

                if (curr->left) q.push({curr->left, 2 * idx + 1});
                if (curr->right) q.push({curr->right, 2 * idx + 2});
            }
        }
    }

    bool find(int target) {
        return s.count(target);
    }
};
