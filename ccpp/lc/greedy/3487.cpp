#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maxSum(std::vector<int> &nums) {
        std::unordered_set<int> numsSet;
        for (int n : nums) {
            if (n > 0) numsSet.emplace(n);
        }

        if (numsSet.empty()) return *std::max_element(nums.begin(), nums.end());
        return std::accumulate(numsSet.begin(), numsSet.end(), 0);
    }
};
