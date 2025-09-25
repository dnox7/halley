#include <climits>
#include <vector>

class Solution {
  public:
    int earliestFinishTime(std::vector<int> &landStartTime, std::vector<int> &landDuration, std::vector<int> &waterStartTime,
                           std::vector<int> &waterDuration) {
        int res = INT_MAX;

        int n = landStartTime.size();
        int minEnd = INT_MAX;
        for (int i = 0; i < n; i++) minEnd = std::min(minEnd, landStartTime[i] + landDuration[i]);

        int m = waterStartTime.size();
        for (int i = 0; i < m; i++) res = std::min(res, waterDuration[i] + std::max(minEnd, waterStartTime[i]));

        minEnd = INT_MAX;
        for (int i = 0; i < m; i++) minEnd = std::min(minEnd, waterStartTime[i] + waterDuration[i]);

        for (int i = 0; i < n; i++) res = std::min(res, landDuration[i] + std::max(minEnd, landStartTime[i]));
        return res;
    }
};
