#include <algorithm>
#include <vector>

class Solution {
  private:
    int count(int target, int n, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return n - left;
    }

  public:
    int specialArray(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxEle = nums[n - 1];

        int res = 1;
        while (res <= maxEle) {
            if (res == count(res, n, nums)) return res;
            res++;
        }
        return -1;
    }
};
