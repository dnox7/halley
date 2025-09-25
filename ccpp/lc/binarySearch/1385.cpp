#include <algorithm>
#include <vector>

class Solution {
  private:
    int findClosest(int n, int target, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

  public:
    int findTheDistanceValue(std::vector<int> &arr1, std::vector<int> &arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int m = arr1.size(), n = arr2.size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            int idx = findClosest(n, arr1[i], arr2);
            if (idx < n && (arr2[idx] == arr1[i] || arr2[idx] - arr1[i] <= d)) continue;
            if (idx > 0 && arr1[i] - arr2[idx - 1] <= d) continue;
            res++;
        }
        return res;
    }
};
