#include <numeric>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> adj;

    long long dfs(int curr, int parent, const std::vector<int> &values) {
        if (adj[curr].size() == 1 && curr != 0) return values[curr];
        long long s = 0;
        for (const int &neighbor : adj[curr]) {
            if (neighbor == parent) continue;
            s += dfs(neighbor, curr, values);
        }
        return std::min(s, values[curr] * 1LL);
    }

  public:
    long long maximumScoreAfterOperations(std::vector<std::vector<int>> &edges, std::vector<int> &values) {
        int n = edges.size() + 1;
        adj.resize(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long total = std::accumulate(values.begin(), values.end(), 0LL);
        return total - dfs(0, -1, values);
    }
};
