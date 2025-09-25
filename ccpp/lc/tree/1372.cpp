#include "lc_tree.h"
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int longestZigZag(TreeNode *root) {
        int res = 0;
        dfs(root->right, false, 1, res);
        dfs(root->left, true, 1, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, bool isLeft, int currLen, int &res) {
        if (!root) return;
        res = std::max(res, currLen);

        if (isLeft) {
            dfs(root->right, false, currLen + 1, res);
            dfs(root->left, true, 1, res);
        } else {
            dfs(root->left, true, currLen + 1, res);
            dfs(root->right, false, 1, res);
        }
    }
};

class Solution1 {
  public:
    int longestZigZag(TreeNode *root) {
        return dfs(root)[2];
    }

  private:
    std::vector<int> dfs(TreeNode *root) {
        if (!root) return {-1, -1, -1};
        auto l = dfs(root->left), r = dfs(root->right);
        int res = std::max(std::max(l[1], r[0]) + 1, std::max(l[2], r[2]));
        return {l[1] + 1, r[0] + 1, res};
    }
};
