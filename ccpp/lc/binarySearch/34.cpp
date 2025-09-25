#include <vector>

class Solution {
  private:
    void search(int left, int right, int target, std::vector<int> &pos, const std::vector<int> &arr) {
        if (left > right) return;
        int mid = left + (right - left) / 2;
        search(left, mid - 1, target, pos, arr);
        if (arr[mid] == target) pos.push_back(mid);
        search(mid + 1, right, target, pos, arr);
    }

  public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        std::vector<int> pos;
        search(0, nums.size() - 1, target, pos, nums);
        if (pos.empty()) return {-1, -1};
        return {pos[0], pos.back()};
    }
};
