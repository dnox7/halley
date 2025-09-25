#include "common_ds.h"

class Solution {
  public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (!root) return false;
        return checkPath(root, head);
    }

    bool checkPath(TreeNode *root, ListNode *head) {
        if (!root) return false;
        if (dfs(root, head)) return true;
        return checkPath(root->left, head) || checkPath(root->right, head);
    }

    bool dfs(TreeNode *root, ListNode *head) {
        if (!head) return true;
        if (!root) return false;
        if (root->val != head->val) return false;
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
};
