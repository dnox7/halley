#include "lc_tree.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution2 {
  public:
    int countPairs(TreeNode *root, int distance) {
        convertToGraph(root, nullptr);
        int res = 0;

        for (TreeNode *leaf : leaves) {
            std::queue<TreeNode *> q;
            q.push(leaf);

            std::unordered_set<TreeNode *> visited;
            visited.insert(leaf);

            for (int i = 0; i <= distance; ++i) {
                int n = q.size();
                for (int j = 0; j < n; ++j) {
                    TreeNode *curr = q.front();
                    q.pop();

                    if (curr != leaf && leaves.count(curr)) res++;
                    for (TreeNode *neighbor : adj[curr]) {
                        if (!visited.count(neighbor)) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return res / 2;
    }

  private:
    std::unordered_map<TreeNode *, std::vector<TreeNode *>> adj;
    std::unordered_set<TreeNode *> leaves;

    void convertToGraph(TreeNode *root, TreeNode *parent) {
        if (parent) adj[root].push_back(parent);
        if (!root->left && !root->right) {
            leaves.insert(root);
            return;
        }

        if (root->left) {
            adj[root].push_back(root->left);
            convertToGraph(root->left, root);
        }

        if (root->right) {
            adj[root].push_back(root->right);
            convertToGraph(root->right, root);
        }
    }
};
