#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findLHS(std::vector<int> &nums) {
        std::unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        int res = 0;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (freq.find(it->first + 1) != freq.end()) {
                res = std::max(res, it->second + freq[it->first + 1]);
            }
        }
        return res;
    }
};

class Solution1 {
  public:
    int findLHS(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int i = 0, maxLen = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            while (nums[j] - nums[i] > 1) i++;
            if (nums[j] - nums[i] == 1) maxLen = std::max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
