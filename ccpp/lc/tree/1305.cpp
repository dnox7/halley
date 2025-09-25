#include "lc_tree.h"

class Solution {
  public:
    std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        std::vector<int> inorder1, inorder2;
        dfs(root1, inorder1);
        dfs(root2, inorder2);
        std::vector<int> res;

        int i = 0, j = 0, m = inorder1.size(), n = inorder2.size();
        while (i < m && j < n) {
            if (inorder1[i] < inorder2[j]) res.push_back(inorder1[i]), i++;
            else res.push_back(inorder2[j]), j++;
        }

        while (i < m) res.push_back(inorder1[i]), i++;
        while (j < n) res.push_back(inorder2[j]), j++;
        return res;
    }

    void dfs(TreeNode *root, std::vector<int> &inorder) {
        if (!root) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};
