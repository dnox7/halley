#include "lc_tree.h"
#include <cstdarg>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        std::unordered_map<TreeNode *, TreeNode *> parent;
        std::queue<TreeNode *> q1;

        q1.push({root});
        while (!q1.empty()) {
            TreeNode *curr = q1.front();
            q1.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q1.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q1.push(curr->right);
            }
        }

        std::vector<int> res;
        std::queue<std::pair<TreeNode *, int>> q2;
        std::unordered_set<TreeNode *> visited;

        q2.push({target, 0});
        visited.insert(target);
        while (!q2.empty()) {
            auto [curr, dist] = q2.front();
            q2.pop();

            if (dist == k) {
                res.push_back(curr->val);
                continue;
            }

            if (curr->left && !visited.count(curr->left)) {
                visited.insert(curr->left);
                q2.push({curr->left, dist + 1});
            }

            if (curr->right && !visited.count(curr->right)) {
                visited.insert(curr->right);
                q2.push({curr->right, dist + 1});
            }

            if (parent.count(curr) && !visited.count(parent[curr])) {
                visited.insert(parent[curr]);
                q2.push({parent[curr], dist + 1});
            }
        }
        return res;
    }
};

class Solution1 {
  private:
    std::unordered_map<int, std::vector<TreeNode *>> m;

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

  public:
    std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> visited;
        std::vector<int> res;

        convertToGraph(root);
        q.push({target->val, 0});
        visited.insert(target->val);

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (dist == k) {
                res.push_back(curr);
                continue;
            }

            for (const TreeNode *node : m[curr]) {
                if (!visited.count(node->val)) {
                    visited.insert(node->val);
                    q.push({node->val, dist + 1});
                }
            }
        }
        return res;
    }
};
