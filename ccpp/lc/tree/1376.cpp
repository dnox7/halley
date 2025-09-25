#include <climits>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numOfMinutes(int n, int headID, std::vector<int> &manager, std::vector<int> &informTime) {
        std::unordered_map<int, std::vector<int>> graph;
        for (int i = 0; i < n; ++i) graph[manager[i]].push_back(i);
        return dfs(headID, graph, informTime);
    }

    int dfs(int curr, const std::unordered_map<int, std::vector<int>> &graph,
            const std::vector<int> &informTime) {
        int max = 0;
        if (!graph.count(curr)) return max;
        for (int sub : graph.at(curr)) max = std::max(max, dfs(sub, graph, informTime));
        return max + informTime[curr];
    }
};
