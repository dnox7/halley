#include <algorithm>
#include <vector>

class Solution {
  private:
    int search(int left, int right, int key, const std::vector<int> &arr) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }

  public:
    int countPairs(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int res = 0;
        for (int i = 0; i < n - 1; i++) res += search(i + 1, n - 1, target - nums[i], nums) - i;
        return res;
    }
};
