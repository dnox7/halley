#include <cmath>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> adj;

    long long dfs(int curr, int parent, int seats, long long &res) {
        long long treeSize = 1;
        for (const int &neighbor : adj[curr]) {
            if (neighbor == parent) continue;
            treeSize += dfs(neighbor, curr, seats, res);
        }
        if (curr != 0) res += std::ceil((double)treeSize / seats);
        return treeSize;
    }

  public:
    long long minimumFuelCost(std::vector<std::vector<int>> &roads, int seats) {
        int n = roads.size();
        adj.resize(n + 1);
        for (const auto &r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        long long res = 0;
        dfs(0, -1, seats, res);
        return res;
    }
};
