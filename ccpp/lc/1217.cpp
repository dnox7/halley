#include <vector>

class Solution {
  public:
    int minCostToMoveChips(std::vector<int> &position) {
        int count[2] = {};
        for (int p : position) ++count[p & 1];
        return std::min(count[0], count[1]);
    }
};
