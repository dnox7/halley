#include <vector>

class NumMatrix {
  public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {}

    int sumRegion(int r1, int c1, int r2, int c2) {}
};

class NumMatrix1 {
  private:
    std::vector<std::vector<int>> prefixSums;

  public:
    NumMatrix1(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
            this->prefixSums.push_back(matrix[i]);
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int res = 0;
        for (int i = r1; i <= r2; ++i) {
            res += prefixSums[i][c2] - (c1 == 0 ? 0 : prefixSums[i][c1 - 1]);
        }
        return res;
    }
};
