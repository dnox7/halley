#include <set>
#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<int> &nums) {
        std::set<int> s(nums.begin(), nums.end());
        return s.count(0) != 0 ? s.size() - 1 : s.size();
    }
};
