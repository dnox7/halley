#include "lc_tree.h"
#include <climits>
#include <unordered_map>

class Solution {
  public:
    std::vector<int> findFrequentTreeSum(TreeNode *root) {
        std::unordered_map<int, int> m;
        calcSum(root, m);

        int maxFreq = INT_MIN;
        for (const auto &[sum, freq] : m) maxFreq = std::max(maxFreq, freq);

        std::vector<int> res;
        for (const auto &[sum, freq] : m) {
            if (freq == maxFreq) res.push_back(sum);
        }
        return res;
    }

    int calcSum(TreeNode *root, std::unordered_map<int, int> &m) {
        if (!root) return 0;
        root->val += calcSum(root->left, m) + calcSum(root->right, m);
        m[root->val]++;
        return root->val;
    }
};
