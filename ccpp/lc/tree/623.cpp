#include "lc_tree.h"
#include <queue>

class Solution {
  public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        std::queue<TreeNode *> q;
        q.push(root);
        int currDepth = 0;
        while (!q.empty()) {
            int n = q.size();
            currDepth++;
            if (currDepth == depth) break;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();

                TreeNode *tmpLeft = curr->left;
                TreeNode *tmpRight = curr->right;

                if (currDepth + 1 == depth) {
                    TreeNode *newLeft = new TreeNode(val);
                    newLeft->left = tmpLeft;
                    curr->left = newLeft;

                    TreeNode *newRight = new TreeNode(val);
                    newRight->right = tmpRight;
                    curr->right = newRight;
                }

                if (tmpLeft) q.push(tmpLeft);
                if (tmpRight) q.push(tmpRight);
            }
        }
        return root;
    }
};
