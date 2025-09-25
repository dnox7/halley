#include <vector>

class Solution {
  public:
    int countPartitions(std::vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) nums[i] += nums[i - 1];
        if (nums[n - 1] % 2 == 0) return n - 1;
        return 0;
    }
};
