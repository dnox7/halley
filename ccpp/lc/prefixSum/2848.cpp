#include <algorithm>
#include <vector>

class Solution {
  public:
    int numberOfPoints(std::vector<std::vector<int>> &nums) {
        auto comparator = [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[0] < b[0]; };
        std::sort(nums.begin(), nums.end(), comparator);
        int start = 0, res = 0;
        for (const std::vector<int> &ele : nums) {
            if (ele[0] > start) res += ele[1] - ele[0] + 1;
            else if (ele[1] > start) res += ele[1] - start;
            start = std::max(start, ele[1]);
        }
        return res;
    }
};
