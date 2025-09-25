#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<std::vector<int>> &grid) {
        int res = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 1; i < grid.size(); i++) {
                if (grid[i][j] > grid[i - 1][j]) continue;
                res += grid[i - 1][j] + 1 - grid[i][j];
                grid[i][j] = grid[i - 1][j] + 1;
            }
        }
        return res;
    }
};
