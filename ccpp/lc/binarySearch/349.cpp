#include <algorithm>
#include <vector>

class Solution {
  private:
    bool binarySearch(const std::vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    };

  public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums1[i] == nums1[i - 1]) continue;
            if (binarySearch(nums2, nums1[i])) res.push_back(nums1[i]);
        }
        return res;
    }
};
