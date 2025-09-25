#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int> countSubTrees(int n, std::vector<std::vector<int>> &edges, std::string labels) {
        std::vector<int> res;
        res.resize(labels.size());
        adj.resize(labels.size());
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, res, labels);
        return res;
    }

  private:
    std::vector<std::vector<int>> adj;

    std::vector<int> dfs(int curr, int parent, std::vector<int> &res, const std::string &label) {
        std::vector<int> freq(26, 0);
        freq[label[curr] - 'a']++;
        for (int &node : adj[curr]) {
            if (node == parent) continue;
            auto fst = dfs(node, curr, res, label);
            for (int i = 0; i < 26; ++i) freq[i] += fst[i];
        }
        res[curr] = freq[label[curr] - 'a'];
        return freq;
    }
};
