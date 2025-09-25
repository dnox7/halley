#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> maxKDistinct(std::vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end(), std::greater<>());
        std::vector<int> res;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (k == 0) break;
            if (!res.empty() && res[res.size() - 1] == nums[i]) continue;
            res.push_back(nums[i]);
            k--;
        }
        return res;
    }
};
