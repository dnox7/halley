#include <algorithm>
#include <vector>

class Solution {
  private:
    int search(int n, const std::vector<int> &arr, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

  public:
    bool checkIfExist(std::vector<int> &arr) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i) {
            if (arr[i] > arr[n - 1] / 2) break;
            int j = search(n, arr, arr[i] * 2);
            if (j != -1 && j != i) return true;
        }
        return false;
    }
};
