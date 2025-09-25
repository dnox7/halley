#include <vector>

class Solution {
  public:
    static constexpr int DIRECTIONS[5] = {0, 1, 0, -1, 0};

    int getMaximumGold(std::vector<std::vector<int>> &grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = std::max(res, backtrack(i, j, m, n, grid));
            }
        }
        return res;
    }

    int backtrack(int x, int y, int m, int n,
                  std::vector<std::vector<int>> &grid) {
        if ((x < 0 || x >= m) || (y < 0 || y >= n) || grid[x][y] == 0) return 0;

        int curr = grid[x][y], maxGold = 0;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int newX = x + DIRECTIONS[i], newY = y + DIRECTIONS[i + 1];
            int k = backtrack(newX, newY, m, n, grid);
            maxGold = std::max(maxGold, k);
        }
        grid[x][y] = curr;
        return curr + maxGold;
    }
};
