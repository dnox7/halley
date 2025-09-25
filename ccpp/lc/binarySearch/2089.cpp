#include <algorithm>
#include <vector>

class Solution {
  private:
    void search(int left, int right, int target, std::vector<int> &res, const std::vector<int> &arr) {
        if (left > right) return;
        int mid = left + (right - left) / 2;
        search(left, mid - 1, target, res, arr);
        if (arr[mid] == target) res.push_back(mid);
        search(mid + 1, right, target, res, arr);
    }

  public:
    std::vector<int> targetIndices(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        search(0, nums.size() - 1, target, res, nums);
        return res;
    }
};
