#include "lc_tree.h"

class Solution {
  public:
    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder) {
        int preIdx = 0;
        return build(preorder, postorder, preIdx, 0, preorder.size() - 1, preorder.size());
    }

    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &postorder, int &preIdx, int low, int height, int n) {
        if (preIdx >= n || low > height) return nullptr;
        TreeNode *root = new TreeNode(preorder[preIdx]);
        preIdx++;
        if (low == height) return root;

        int i = low;
        while (i <= height) {
            if (preorder[preIdx] == postorder[i]) break;
            i++;
        }

        if (i <= height) {
            root->left = build(preorder, postorder, preIdx, low, i, n);
            root->right = build(preorder, postorder, preIdx, i + 1, height - 1, n);
        }
        return root;
    }
};
