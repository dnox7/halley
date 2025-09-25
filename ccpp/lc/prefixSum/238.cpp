#include <vector>

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> res(nums);
        for (int i = n - 2; i >= 0; --i) res[i] *= res[i + 1];
        for (int i = 0; i < n; ++i) {
            int right = i == n - 1 ? 1 : res[i + 1];
            int left = i == 0 ? 1 : nums[i - 1];
            if (i != 0) nums[i] *= nums[i - 1];
            res[i] = left * right;
        }
        return res;
    }
};
