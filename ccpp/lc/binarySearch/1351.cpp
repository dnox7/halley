#include <vector>

class Solution {
  private:
    int count(int n, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= 0) left = mid + 1;
            else right = mid - 1;
        }
        return n - left;
    }

  public:
    int countNegatives(std::vector<std::vector<int>> &grid) {
        int n = grid[0].size();
        int res = 0;
        for (const std::vector<int> &row : grid) res += count(n, row);
        return res;
    }
};
