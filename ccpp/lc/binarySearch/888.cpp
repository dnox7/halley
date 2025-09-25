#include <algorithm>
#include <vector>

class Solution {
  private:
    bool binarySearch(const std::vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

  public:
    std::vector<int> fairCandySwap(std::vector<int> &aliceSizes, std::vector<int> &bobSizes) {
        std::sort(aliceSizes.begin(), aliceSizes.end());
        std::sort(bobSizes.begin(), bobSizes.end());

        int i = 0, j = 0;
        int m = aliceSizes.size(), n = bobSizes.size();
        int aliceTotal = 0, bobTotal = 0;
        while (i < m || j < n) {
            if (i < m) {
                aliceTotal += aliceSizes[i];
                i++;
            }

            if (j < n) {
                bobTotal += bobSizes[j];
                j++;
            }
        }

        int diff = (aliceTotal + bobTotal) / 2 - aliceTotal;
        for (int k = 0; k < m; ++k) {
            if (k != 0 && aliceSizes[k] == aliceSizes[k - 1]) continue;
            if (binarySearch(bobSizes, aliceSizes[k] + diff)) return {aliceSizes[k], aliceSizes[k] + diff};
        }
        return {};
    }
};
