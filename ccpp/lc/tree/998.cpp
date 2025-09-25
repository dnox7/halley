#include "lc_tree.h"

class Solution {
  public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode *newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }
};
