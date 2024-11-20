#include <algorithm>
#include <vector>

class Solution {
  public:
    int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b) {
                      return a[1] > b[1];
                  });

        int res = 0, i = 0;
        while (truckSize > 0 && i < boxTypes.size()) {
            if (boxTypes[i][0] > truckSize) {
                res += truckSize * boxTypes[i][1];
                break;
            }

            res += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
            i++;
        }
        return res;
    }
};
