#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    int maxLength(std::vector<int> &nums) {
        int res = 0, n = nums.size(), maxLcm = 36'288'000;
        for (int i = 0; i < n; ++i) {
            int g = nums[i], l = nums[i], p = 1;
            for (int j = i; j < n; ++j) {
                p *= nums[j];
                if (p > maxLcm) break;
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, nums[j]);
                if (p == g * l) res = std::max(res, j - i + 1);
            }
        }
        return res;
    }
};
