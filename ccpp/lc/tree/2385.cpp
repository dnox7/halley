#include "lc_tree.h"
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    int amountOfTime(TreeNode *root, int start) {
        int res = 0;
        solve(root, start, res);
        return res;
    }

    int solve(TreeNode *root, int start, int &res) {
        if (!root) return 0;
        int leftHeight = solve(root->left, start, res);
        int rightHeight = solve(root->right, start, res);

        if (root->val == start) {
            res = std::max(leftHeight, rightHeight);
            return -1;
        }

        if (leftHeight >= 0 && rightHeight >= 0) return std::max(leftHeight, rightHeight) + 1;
        res = std::max(res, std::abs(leftHeight) + std::abs(rightHeight));
        return std::min(leftHeight, rightHeight) - 1;
    }
};

class Solution1 {
    std::unordered_map<int, std::vector<TreeNode *>> m;

  public:
    int amountOfTime(TreeNode *root, int start) {
        convertToGraph(root);
        std::unordered_set<int> visited;
        std::queue<std::pair<int, int>> q;

        int res = 0;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            for (const TreeNode *node : m[curr]) {
                if (!visited.count(node->val)) {
                    visited.insert(node->val);
                    q.push({node->val, dist + 1});
                }
            }

            if (m[curr].size() == 1 && visited.count(m[curr][0]->val)) {
                res = std::max(res, dist);
            }
        }
        return res;
    }

    void convertToGraph(TreeNode *root) {
        std::queue<std::pair<TreeNode *, TreeNode *>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [curr, parent] = q.front();
                q.pop();
                if (parent) m[curr->val].push_back(parent);

                if (curr->left) {
                    m[curr->val].push_back(curr->left);
                    q.push({curr->left, curr});
                }

                if (curr->right) {
                    m[curr->val].push_back(curr->right);
                    q.push({curr->right, curr});
                }
            }
        }
    }
};
