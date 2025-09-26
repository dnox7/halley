#include <vector>

class Solution {
  public:
    double findMaxAverage(std::vector<int> &nums, int k) {
        int total = 0, n = nums.size();
        for (int i = 0; i < k; ++i) total += nums[i];
        int maxSum = total;
        for (int i = 1; i <= n - k; ++i) {
            total += nums[i + k - 1] - nums[i - 1];
            maxSum = std::max(maxSum, total);
        }
        return static_cast<double>(maxSum) / k;
    }
};
