#include <vector>

class Solution {
  public:
    int numberOfAlternatingGroups(std::vector<int> &colors) {
        int res = 0, n = colors.size();
        for (int i = 0; i < n; ++i) {
            int prev = (i + n - 1) % n, next = (i + n + 1) % n;
            if (colors[i] != colors[prev] && colors[i] != colors[next]) res++;
        }
        return res;
    }
};
