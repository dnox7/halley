#include "lc_tree.h"

class Solution {
  public:
    TreeNode *balanceBST(TreeNode *root) {
        std::vector<int> inorder;
        dfs(root, inorder);
        return construct(0, inorder.size() - 1, inorder);
    }

    TreeNode *construct(int start, int end, const std::vector<int> &inorder) {
        if (start > end) return nullptr;
        int rootIdx = start + (end - start) / 2;
        TreeNode *root = new TreeNode(inorder[rootIdx]);
        root->left = construct(start, rootIdx - 1, inorder);
        root->right = construct(rootIdx + 1, end, inorder);
        return root;
    }

    void dfs(TreeNode *root, std::vector<int> &inorder) {
        if (!root) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};
