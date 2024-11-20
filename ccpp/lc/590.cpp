#include "common_ds.h"

class Solution {
  public:
    void traverse(Node *root, std::vector<int> &res) {
        if (!root) return;
        for (auto child : root->children) traverse(child, res);
        res.push_back(root->val);
    }

    std::vector<int> postorder(Node *root) {
        std::vector<int> res;
        traverse(root, res);
        return res;
    }
};
