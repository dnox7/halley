#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        std::vector<int> res;
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        return res;
    }
};
