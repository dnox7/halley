#include "lc_tree.h"

class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return root;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        if (!root->right) {
            TreeNode *left = root->left;
            delete root;
            return left;
        }

        TreeNode *right = root->right;
        TreeNode *curr = right->left;
        if (!curr) right->left = root->left;
        else {
            while (curr->left) curr = curr->left;
            curr->left = root->left;
        }
        delete root;
        return right;
    }
};
