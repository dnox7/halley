#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    int minimumBoxes(std::vector<int> &apple, std::vector<int> &capacity) {
        int total = std::accumulate(apple.begin(), apple.end(), 0);
        std::sort(capacity.begin(), capacity.end(), std::greater<>());
        int res = 0;
        for (int i = 0; i < capacity.size(); i++) {
            if (total <= 0) break;
            total -= capacity[i];
            res++;
        }
        return res;
    }
};
