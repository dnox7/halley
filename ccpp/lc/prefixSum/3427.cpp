#include <vector>

class Solution {
  public:
    int subarraySum(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> s(n, 0);
        s[0] = nums[0];
        for (int i = 1; i < n; ++i) s[i] = nums[i] + s[i - 1];

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int start = std::max(0, i - nums[i]);
            res += s[i] - s[start] + nums[start];
        }
        return res;
    }
};
