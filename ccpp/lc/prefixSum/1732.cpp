#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int largestAltitude(std::vector<int> &gain) {
        int n = gain.size(), res = std::max(gain[0], 0);
        for (int i = 1; i < n; ++i) {
            gain[i] += gain[i - 1];
            res = std::max(res, gain[i]);
        }
        return res;
    }
};
