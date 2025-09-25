#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
  private:
    void countZero(int left, int right, int &res, const std::vector<int> &arr) {
        if (left > right) return;
        int mid = left + (right - left) / 2;
        if (arr[mid] == 0) res++;
        countZero(left, mid - 1, res, arr);
        countZero(mid + 1, right, res, arr);
    }

    int countNeg(int n, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < 0) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

  public:
    int maximumCount(std::vector<int> &nums) {
        int n = nums.size();
        int z;
        countZero(0, n - 1, z, nums);
        int k = countNeg(n, nums);
        return std::max(k, n - k - z);
    }
};
