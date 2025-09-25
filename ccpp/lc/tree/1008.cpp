#include "lc_tree.h"

class Solution {
  public:
    TreeNode *bstFromPreorder(std::vector<int> &preorder) {
        return construct(0, preorder.size(), preorder);
    }

    TreeNode *construct(int start, int end, const std::vector<int> &preorder) {
        if (start >= end) return nullptr;
        int i = start + 1;
        while (i < end && preorder[i] < preorder[start]) i++;
        TreeNode *root = new TreeNode(preorder[start]);
        root->left = construct(start + 1, i, preorder);
        root->right = construct(i, end, preorder);
        return root;
    }
};
