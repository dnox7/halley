#include "lc_tree.h"

#define MOD 1000000007

class Solution {
  public:
    int maxProduct(TreeNode *root) {
        std::vector<int> totals;
        int totalSum = calcTotal(root, totals);

        long long maxProd = 0;

        for (int t : totals) {
            long long prod = 1LL * t * (totalSum - t);
            maxProd = std::max(maxProd, prod);
        }

        return maxProd % MOD;
    }

    int calcTotal(TreeNode *root, std::vector<int> &totals) {
        if (!root) return 0;
        int sum = root->val + calcTotal(root->left, totals) + calcTotal(root->right, totals);
        totals.push_back(sum);
        return sum;
    }
};
