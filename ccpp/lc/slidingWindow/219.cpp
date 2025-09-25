#include <unordered_map>
#include <vector>

class Solution {
  public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        if (k == 0) return false;
        int n = nums.size();
        std::unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end() && (i - m[nums[i]] <= k)) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }

    bool containsNearbyDuplicate1(std::vector<int> &nums, int k) {
        if (k == 0) return false;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= std::min(i + k, n - 1); ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
