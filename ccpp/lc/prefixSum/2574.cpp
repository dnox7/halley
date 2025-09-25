#include <cstdlib>
#include <vector>

class Solution {
  public:
    std::vector<int> leftRightDifference(std::vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) nums[i] += nums[i - 1];

        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            int left = (i == 0) ? 0 : nums[i - 1];
            int right = (i == n - 1) ? 0 : nums[n - 1] - nums[i];
            res.push_back(std::abs(left - right));
        }
        return res;
    }
};
