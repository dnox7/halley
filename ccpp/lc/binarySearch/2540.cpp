#include <vector>

class Solution {
  private:
    bool search(int n, int target, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

  public:
    int getCommon(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n = nums2.size();
        for (const int &k : nums1) {
            if (search(n, k, nums2)) return k;
        }
        return -1;
    }
};
