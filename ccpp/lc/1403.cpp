#include <numeric>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> minSubsequence(std::vector<int> &nums) {
        int half_sum = std::accumulate(nums.begin(), nums.end(), 0) / 2;
        std::priority_queue<int> q(nums.begin(), nums.end());
        std::vector<int> res;
        int sub_sum = 0;
        while (sub_sum <= half_sum) {
            res.push_back(q.top());
            sub_sum += res.back();
            q.pop();
        }
        return res;
    }
};
