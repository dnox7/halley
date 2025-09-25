#include <csignal>
#include <vector>

class Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (col >= 0 && row < matrix.size()) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};

class Solution1 {
  private:
    bool binarySearch(int n, int target, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i].back()) {
                if (binarySearch(n, target, matrix[i])) return true;
            }
        }
        return false;
    }
};
