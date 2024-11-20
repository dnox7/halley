#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> answerQueries(std::vector<int> &nums,
                                   std::vector<int> &queries) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) nums[i] += nums[i - 1];

        std::vector<int> res;
        for (int q : queries) res.push_back(binarySearch(nums, n, q));
        return res;
    }

    int binarySearch(const std::vector<int> &nums, int n, int target) {
        int left = 0, right = n - 1, idx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                idx = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return idx + 1;
    }

    std::vector<int> answerQueries1(std::vector<int> &nums,
                                    std::vector<int> &queries) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        for (int q : queries) {
            res.push_back(findMaxSize(nums, q));
        }
        return res;
    }

    int findMaxSize(const std::vector<int> &nums, int target) {
        int total = 0, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + total > target) break;
            total += nums[i];
            len++;
        }
        return len;
    }
};
