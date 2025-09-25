#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findMaxLength(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> firstIdx(2 * n + 1, -2);

        firstIdx[n] = -1;
        int res = 0, prefix = 0;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i] == 0 ? -1 : 1;
            int idx = prefix + n;
            if (!firstIdx[idx] == -2) firstIdx[idx] = i;
            else res = std::max(res, i - firstIdx[idx]);
        }
        return res;
    }
};

class Solution1 {
  public:
    int findMaxLength(std::vector<int> &nums) {
        int n = nums.size();
        std::unordered_map<int, int> firstIdx;

        firstIdx[0] = -1;
        int res = 0, prefix = 0;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i] == 0 ? -1 : 1;
            if (!firstIdx.count(prefix)) firstIdx[prefix] = i;
            else res = std::max(res, i - firstIdx[prefix]);
        }
        return res;
    }
};