#include <vector>

class Solution {
  public:
    bool isCovered(std::vector<std::vector<int>> &ranges, int left, int right) {
        const int MAX = 52;
        int diff[MAX] = {0};
        for (const std::vector<int> &range : ranges) {
            diff[range[0]] += 1;
            diff[range[1] + 1] -= 1;
        }

        for (int i = 1; i < MAX; ++i) {
            diff[i] += diff[i - 1];
            if (i >= left && i <= right && diff[i] <= 0) return false;
        }
        return true;
    }
};
