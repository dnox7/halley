#include "lc_tree.h"

class Solution {
  public:
    void traverse(Node *root, std::vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        for (auto child : root->children) traverse(child, res);
    }

    std::vector<int> preorder(Node *root) {
        std::vector<int> res;
        traverse(root, res);
        return res;
    }
};
