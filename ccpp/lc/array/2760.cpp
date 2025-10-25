#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int longestAlternatingArray(std::vector<int> &nums, int threshold) {
        int res = 0, i = 0, left = INT_MAX, n = nums.size();
        while (i < n) {
            if (nums[i] > threshold ||
                (i >= 1 && !((nums[i] + nums[i - 1]) & 1))) {
                res = std::max(res, i - left);
                left = INT_MAX;
            }

            if (left == INT_MAX && nums[i] <= threshold && !(nums[i] & 1)) {
                left = i;
            }
            i++;
        }
        res = std::max(res, n - left);
        return res;
    }
};
