#include <unordered_map>
#include <vector>

class Solution {
  public:
    bool checkSubarraySum(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        std::unordered_map<int, int> freq;

        freq[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            int key = prefix[i] % k;
            if (!freq.count(key)) freq[key] = i;
            if (i - freq[key] > 1) return true;
        }
        return false;
    }
};
