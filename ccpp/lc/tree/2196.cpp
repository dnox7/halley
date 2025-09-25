#include "lc_tree.h"
#include <unordered_map>
#include <unordered_set>

class Solution {
  private:
    std::unordered_map<int, TreeNode *> nodes;
    std::unordered_set<TreeNode *> s;

    TreeNode *getNode(int val) {
        if (nodes.count(val)) return nodes[val];
        TreeNode *node = new TreeNode(val);
        nodes[val] = node;
        return node;
    }

  public:
    TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
        for (const auto &des : descriptions) {
            TreeNode *parent = getNode(des[0]);
            TreeNode *child = getNode(des[1]);
            s.insert(child);
            if (des[2] == 1) parent->left = child;
            else parent->right = child;
        }

        for (const auto &[val, node] : nodes) {
            if (!s.count(node)) return node;
        }
        return nullptr;
    }
};
