#include <unordered_map>
#include <vector>

class Solution {
  public:
    int subarraySum(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        std::unordered_map<int, int> freq;

        for (int i = 1; i < n + 1; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            freq[prefix[i]]++;
        }

        int res = 0;
        for (int i = 0; i < n + 1; ++i) {
            if (i != 0) freq[prefix[i]]--;
            int target = prefix[i] + k;
            if (freq.count(target)) res += freq[target];
        }
        return res;
    }
};
