#include <unordered_map>
#include <vector>

class Solution {
  public:
    int subarraysDivByK(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;

        freq[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (i != 0) nums[i] += nums[i - 1];
            int key = ((nums[i] % k) + k) % k;
            freq[key]++;
        }

        int res = 0;
        for (const auto &[s, f] : freq) res += f * (f - 1) / 2;
        return res;
    }
};
