#include <cstdlib>
#include <vector>

class Solution {
  public:
    int countValidSelections(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) prefixSum[i] = nums[i] + prefixSum[i - 1];

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) continue;
            int left = (i == 0) ? 0 : prefixSum[i - 1];
            int right = (i == n - 1) ? 0 : prefixSum[n - 1] - prefixSum[i];
            if (left == right) res += 2;
            if (std::abs(left - right) == 1) res += 1;
        }
        return res;
    }
};
