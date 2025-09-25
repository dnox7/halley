#include "lc_tree.h"
#include <cmath>
#include <queue>
#include <string>
#include <tuple>

class Solution {
  public:
    std::vector<std::vector<std::string>> printTree(TreeNode *root) {
        int h = depth(root) - 1;
        int m = h + 1;
        int n = std::pow(2, h + 1) - 1;
        std::vector<std::vector<std::string>> res(m, std::vector<std::string>(n));

        std::queue<std::tuple<TreeNode *, int, int>> q;
        q.push({root, 0, (n - 1) / 2});

        while (!q.empty()) {
            int qLen = q.size();

            for (int i = 0; i < qLen; ++i) {
                auto [curr, row, col] = q.front();
                q.pop();
                res[row][col] = std::to_string(curr->val);
                if (curr->left) q.push({curr->left, row + 1, col - (int)pow(2, h - row - 1)});
                if (curr->right) q.push({curr->right, row + 1, col + (int)pow(2, h - row - 1)});
            }
        }
        return res;
    }

    int depth(TreeNode *root) {
        return root ? std::max(depth(root->left), depth(root->right)) + 1 : 0;
    }
};
