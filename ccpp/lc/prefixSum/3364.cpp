#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int minimumSumSubarray(std::vector<int> &nums, int l, int r) {
        int n = nums.size(), sum = 0, res = INT_MAX;
        for (int i = 0; i < l - 1; ++i) sum += nums[i];
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            if (j >= n) break;
            int curr = sum;
            sum += nums[j];
            while (j < std::min(n, i + r)) {
                curr += nums[j];
                if (curr > 0) res = std::min(res, curr);
                j++;
            }
            sum -= nums[i];
        }
        return res == INT_MAX ? -1 : res;
    }
};
