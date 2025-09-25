#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int minimumDifference(std::vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        int res = INT_MAX, n = nums.size();
        for (int i = 0; i <= n - k; ++i)
            res = std::min(res, nums[i + k - 1] - nums[i]);
        return res;
    }
};
