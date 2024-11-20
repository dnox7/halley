#include "common_ds.h"

class Solution {
  public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target) {
        if (original == nullptr || original == target) return cloned;
        TreeNode *res = getTargetCopy(original->left, cloned->left, target);
        if (res) return res;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
