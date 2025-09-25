#include <vector>

class Solution {
  public:
    int findTargetSumWays_Backtrack(std::vector<int> &nums, int target) {
        int res = 0;
        backtrack(0, 0, res, nums, nums.size(), target);
        return res;
    }

    void backtrack(int idx, int sum, int &res, std::vector<int> &nums, int n, int target) {
        if (idx == n) {
            if (sum == target) res++;
            return;
        }
        for (int k : {-1, 1}) backtrack(idx + 1, sum + k * nums[idx], res, nums, n, target);
    }
};
