#include "lc_tree.h"
#include <cstdlib>
#include <queue>
#include <stack>

class BSTIteratorStack {
    std::stack<TreeNode *> s;

  public:
    BSTIteratorStack(TreeNode *root) {
        TreeNode *curr = root;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        TreeNode *res = s.top();
        s.pop();
        TreeNode *curr = res;
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
        }
        return res->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

class BSTIteratorQueue {
    std::queue<int> q;

  public:
    BSTIteratorQueue(TreeNode *root) {
        TreeNode *curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr) prev = prev->right;
                if (prev->right) {
                    prev->right = nullptr;
                    q.push(curr->val);
                    curr = curr->right;
                } else {
                    prev->right = curr;
                    curr = curr->left;
                }
            } else {
                q.push(curr->val);
                curr = curr->right;
            }
        }
    }

    int next() {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};
