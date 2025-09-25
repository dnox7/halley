#include <cmath>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<std::pair<int, int>>> adj;

    void dfs(int curr, int parent, int pathSum, int signalSpeed, int &count) {
        if (pathSum % signalSpeed == 0) count++;
        for (const auto &neighbor : adj[curr]) {
            if (neighbor.first == parent) continue;
            dfs(neighbor.first, curr, pathSum + neighbor.second, signalSpeed, count);
        }
    }

    int countPairs(int root, int signalSpeed) {
        int totalNodes = 0, totalSquare = 0;
        for (const auto &neighbor : adj[root]) {
            int k = 0;
            dfs(neighbor.first, root, neighbor.second, signalSpeed, k);
            totalNodes += k;
            totalSquare += std::pow(k, 2);
        }
        return (std::pow(totalNodes, 2) - totalSquare) / 2;
    }

  public:
    std::vector<int> countPairsOfConnectableServers(std::vector<std::vector<int>> &edges, int signalSpeed) {
        int n = edges.size() + 1;
        adj.resize(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        std::vector<int> res;
        for (int root = 0; root < n; ++root) res.push_back(countPairs(root, signalSpeed));
        return res;
    }
};
