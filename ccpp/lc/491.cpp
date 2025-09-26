#include <climits>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> acc;
        backtrack(0, INT_MIN, nums.size(), acc, res, nums);
        return res;
    }

    void backtrack(int idx, int prev, int n, std::vector<int> &acc,
                   std::vector<std::vector<int>> &res, std::vector<int> &nums) {
        if (idx == n) {
            if (acc.size() > 1) res.push_back(acc);
            return;
        }

        if (acc.empty() || nums[idx] >= acc.back()) {
            acc.push_back(nums[idx]);
            backtrack(idx + 1, nums[idx], n, acc, res, nums);
            acc.pop_back();
        }

        if (nums[idx] == prev) return;
        backtrack(idx + 1, prev, n, acc, res, nums);
    }
};
