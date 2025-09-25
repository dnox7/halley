#include <vector>

class Solution {
  public:
    int minTime(int n, std::vector<std::vector<int>> &edges, std::vector<bool> hasApple) {
        adj.resize(hasApple.size());
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int treeSize = dfs(0, -1, hasApple);
        return treeSize == 0 ? 0 : (treeSize - 1) * 2;
    }

  private:
    std::vector<std::vector<int>> adj;

    int dfs(int curr, int parent, const std::vector<bool> &hasApple) {
        int treeSize = 0;
        for (int &node : adj[curr]) {
            if (node == parent) continue;
            treeSize += dfs(node, curr, hasApple);
        }
        if (treeSize == 0) return hasApple[curr] ? 1 : 0;
        return treeSize + 1;
    }
};
