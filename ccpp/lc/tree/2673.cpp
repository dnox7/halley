#include <cstdlib>
#include <vector>

class Solution {
  private:
    int dfs(int curr, int &res, int n, const std::vector<int> &cost) {
        if (curr >= n) return 0;
        int left = dfs(2 * curr + 1, res, n, cost);
        int right = dfs(2 * curr + 2, res, n, cost);
        res += std::abs(left - right);
        return std::max(left, right) + cost[curr];
    }

  public:
    int minIncrements(int n, std::vector<int> &cost) {
        int res = 0;
        dfs(0, res, n, cost);
        return res;
    }
};
