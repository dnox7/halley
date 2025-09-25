#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> findXSum(std::vector<int> &nums, int k, int x) {
        std::unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i) freq[nums[i]]++;

        int n = nums.size();
        std::vector<int> res = {xsum(freq, x)};
        for (int i = 1; i <= n - k; ++i) {
            freq[nums[i - 1]]--;
            if (!freq[nums[i - 1]]) freq.erase(nums[i - 1]);
            freq[nums[i + k - 1]]++;
            res.push_back(xsum(freq, x));
        }
        return res;
    }

    int xsum(const std::unordered_map<int, int> &freq, int x) {
        std::priority_queue<std::pair<int, int>> q;
        for (const auto &e : freq) q.push({e.second, e.first});

        int i = 0, sum = 0;
        while (i < x && !q.empty()) {
            auto p = q.top();
            sum += p.first * p.second;
            q.pop();
            i++;
        }
        return sum;
    }
};
