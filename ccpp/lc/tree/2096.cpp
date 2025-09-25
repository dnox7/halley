#include "lc_tree.h"
#include <string>

class Solution {
    bool findPath(TreeNode *root, int target, std::string &res) {
        if (!root) return false;
        if (root->val == target) return true;

        res.push_back('L');
        if (findPath(root->left, target, res)) return true;
        res.pop_back();

        res.push_back('R');
        if (findPath(root->right, target, res)) return true;
        res.pop_back();
        return false;
    }

    TreeNode *lca(TreeNode *root, int startVal, int destVal) {
        if (!root || root->val == startVal || root->val == destVal) return root;
        TreeNode *left = lca(root->left, startVal, destVal);
        TreeNode *right = lca(root->right, startVal, destVal);
        return !left ? right : !right ? left : root;
    }

  public:
    std::string getDirections(TreeNode *root, int startValue, int destValue) {
        TreeNode *lcaNode = lca(root, startValue, destValue);
        std::string startPath, destPath;
        findPath(lcaNode, startValue, startPath);
        findPath(lcaNode, destValue, destPath);
        return std::string(startPath.size(), 'U') + destPath;
    }
};
