#include "lc_tree.h"
#include <algorithm>
#include <functional>
#include <vector>

class Solution {
  public:
    int kthLargestPerfectSubtree(TreeNode *root, int k) {
        std::vector<int> treeSizes;
        dfs(root, treeSizes);
        std::sort(treeSizes.begin(), treeSizes.end(), std::greater<int>());
        return k > treeSizes.size() ? -1 : treeSizes[k - 1];
    }

    int dfs(TreeNode *root, std::vector<int> &treeSizes) {
        if (!root) return 0;
        int lc = dfs(root->left, treeSizes);
        int rc = dfs(root->right, treeSizes);
        if (lc != rc || lc == -1) return -1;
        int total = 2 * lc + 1;
        treeSizes.push_back(total);
        return total;
    }
};
