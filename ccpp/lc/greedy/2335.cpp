#include <climits>
#include <vector>

class Solution {
  public:
    int fillCups(std::vector<int> &amount) {
        int max = INT_MIN, sum = 0;
        for (int k : amount) {
            sum += k;
            max = std::max(max, k);
        }
        return std::max((sum + 1) / 2, max);
    }
};
