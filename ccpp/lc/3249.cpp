#include <climits>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countGoodNodes(std::vector<std::vector<int>> &edges) {
        std::unordered_map<int, std::vector<int>> tree;
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(0, -1, res, tree);
        return res;
    }

  private:
    int dfs(int curr, int parent, int &res, std::unordered_map<int, std::vector<int>> &tree) {
        int treeSize = 1, prev = -1, n = tree[curr].size();
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (tree[curr][i] == parent) continue;
            int subtreeSize = dfs(tree[curr][i], curr, res, tree);
            if (prev == -1) prev = subtreeSize;
            if (subtreeSize != prev) flag = false;
            treeSize += subtreeSize;
        }
        if (flag) res++;
        return treeSize + 1;
    }
};
