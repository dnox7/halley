#include <vector>

class Solution {
  public:
    int maxDistance(std::vector<int> &colors) {
        int n = colors.size(), i = 0, j = n - 1;
        while (colors[0] == colors[j]) j--;
        while (colors[n - 1] == colors[i]) i++;
        return std::max(n - 1 - i, j);
    }
};
