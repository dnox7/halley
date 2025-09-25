#include "lc_tree.h"

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int rootVal = root->val, pVal = p->val, qVal = q->val;
        if (rootVal == pVal || rootVal == qVal || (rootVal > pVal && rootVal < qVal) || (rootVal < pVal && rootVal > qVal)) {
            return root;
        }

        if (rootVal > pVal) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }

    TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q) {
        std::vector<int> v1, v2, v3;
        ancestor(root, p, v1);
        ancestor(root, q, v2);

        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                if (v2[j] == v1[i]) v3.push_back(v1[i]);
            }
        }
        return search(root, v3.back());
    }

    void ancestor(TreeNode *root, TreeNode *p, std::vector<int> &v) {
        if (!root) return;
        v.push_back(root->val);

        if (root->val == p->val) return;

        if (root->val > p->val) ancestor(root->left, p, v);
        else ancestor(root->right, p, v);
    }

    TreeNode *search(TreeNode *root, int target) {
        if (!root || root->val == target) return root;
        if (root->val > target) return search(root->left, target);
        return search(root->right, target);
    }
};
