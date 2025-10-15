#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> adj;
    std::vector<bool> restricted;

    void dfs(int node, int parent, int &res) {
        res++;
        for (const int &neighbor : adj[node]) {
            if (neighbor == parent || restricted[neighbor]) continue;
            dfs(neighbor, node, res);
        }
    }

  public:
    int reachableNodes(int n, std::vector<std::vector<int>> &edges, std::vector<int> &restricted) {
        this->restricted = std::vector<bool>(n, false);
        for (int &node : restricted) this->restricted[node] = true;

        adj.resize(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        dfs(0, -1, res);
        return res;
    }
};
