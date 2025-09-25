#include <vector>

class Solution {
  public:
    int returnToBoundaryCount(std::vector<int> &nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
            if (nums[i] == 0) res++;
        }
        return res;
    }
};
