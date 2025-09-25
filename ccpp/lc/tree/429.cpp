#include "lc_tree.h"
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        std::vector<std::vector<int>> res;
        std::queue<Node *> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            std::vector<int> level;
            for (int i = 0; i < n; ++i) {
                Node *curr = q.front();
                q.pop();
                level.push_back(curr->val);

                if (!curr->children.empty()) {
                    for (Node *c : curr->children) q.push(c);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
