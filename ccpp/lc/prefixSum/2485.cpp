#include <cmath>

class Solution {
  public:
    int pivotInteger(int n) {
        int k = n * (n + 1) / 2;
        int sqrtInt = (int)std::sqrt(k);
        if (sqrtInt * sqrtInt == k) return sqrtInt;
        return -1;
    }
};
