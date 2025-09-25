#include <algorithm>
#include <vector>

class Solution {
  private:
    int countSol(int n, const std::vector<int> &row) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

  public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::pair<int, int>> soldiers;

        for (int i = 0; i < m; ++i) soldiers.push_back({countSol(n, mat[i]), i});
        std::sort(soldiers.begin(), soldiers.end());

        std::vector<int> res;
        for (int i = 0; i < k; ++i) res.push_back(soldiers[i].second);
        return res;
    }
};
