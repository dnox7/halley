#include "lc_tree.h"

class Solution {
  public:
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
        return build(0, nums.size(), nums);
    }

    TreeNode *build(int start, int end, const std::vector<int> &nums) {
        if (start >= end) return nullptr;
        int rootIdx = start, rootVal = nums[start];
        for (int i = start; i < end; ++i) {
            if (nums[i] > rootVal) {
                rootVal = nums[i];
                rootIdx = i;
            }
        }

        TreeNode *root = new TreeNode(rootVal);
        root->left = build(start, rootIdx, nums);
        root->right = build(rootIdx + 1, end, nums);
        return root;
    }
};
