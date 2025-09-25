#include "lc_tree.h"
#include <queue>

class CBTInserter {
    TreeNode *root;
    std::vector<TreeNode *> lastLevel, secondLastLevel;

    void bfs(TreeNode *root) {
        std::queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if (!curr) {
                if (q.empty()) break;
                q.push(nullptr);
                secondLastLevel = lastLevel;
                lastLevel = {};
                continue;
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            lastLevel.push_back(curr);
        }
    }

  public:
    CBTInserter(TreeNode *root) {
        this->root = root;
        bfs(root);
    }

    int insert(int val) {
        if (lastLevel.size() == 2 * secondLastLevel.size() || (secondLastLevel.empty() && lastLevel.size() == 1)) {
            secondLastLevel = lastLevel;
            lastLevel = {};
        }
        TreeNode *newNode = new TreeNode(val);
        TreeNode *parent = secondLastLevel[lastLevel.size() / 2];
        if (!parent->left) parent->left = newNode;
        else parent->right = newNode;
        lastLevel.push_back(newNode);
        return parent->val;
    }

    TreeNode *get_root() {
        return root;
    }
};

class CBTInserter1 {
    TreeNode *root;

  public:
    CBTInserter1(TreeNode *_root) {
        root = _root;
    }

    int insert(int val) {
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                else {
                    TreeNode *newNode = new TreeNode(val);
                    curr->left = newNode;
                    return curr->val;
                }

                if (curr->right) q.push(curr->right);
                else {
                    TreeNode *newNode = new TreeNode(val);
                    curr->right = newNode;
                    return curr->val;
                }
            }
        }
        return 0;
    }

    TreeNode *get_root() {
        return root;
    }
};
