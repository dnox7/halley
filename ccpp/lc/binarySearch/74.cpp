#include <vector>

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = (row * col) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int curr = matrix[mid / col][mid % col];
            if (curr == target) return true;
            if (curr < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
