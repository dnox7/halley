#include "lc_tree.h"

class Solution {
  public:
    TreeNode *trimBST(TreeNode *root, int low, int hight) {
        if (!root) return root;
        while (root && (root->val < low || root->val > hight)) {
            if (root->val < low) root = root->right;
            else root = root->left;
        }
        if (!root) return root;
        root->left = trimBST(root->left, low, hight);
        root->right = trimBST(root->right, low, hight);
        return root;
    }
};
