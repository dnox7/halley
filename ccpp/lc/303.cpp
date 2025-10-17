#include <vector>

class NumArray {
  private:
    std::vector<int> nums;

  public:
    NumArray(std::vector<int> &nums) {
        int n = nums.size();
        this->nums = std::vector<int>(n + 1);
        for (int i = 0; i < n; ++i) this->nums[i + 1] = this->nums[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return this->nums[right + 1] - this->nums[left];
    }
};
