#include <climits>
#include <vector>

class Solution {
  public:
    int minStartValue(std::vector<int> &nums) {
        int prefix = 1, n = nums.size(), minSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            nums[i] += prefix;
            prefix = nums[i];
            minSum = std::min(minSum, prefix);
        }
        if (minSum >= 1) return 1;
        return 2 - minSum;
    }
};
