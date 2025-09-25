#include <unordered_map>
#include <vector>

class Solution {
  private:
    std::vector<std::vector<int>> adj;
    std::unordered_map<long long, int> res;

    int countNodes(int root, int n, long long &highestScore) {
        int totalNodes = 1;
        long long k = 1;
        for (const int &child : adj[root]) {
            int subtreeSize = countNodes(child, n, highestScore);
            totalNodes += subtreeSize;
            k *= subtreeSize;
        }
        int rem = n - totalNodes;
        if (rem == 0) rem = 1;
        long long product = k * rem;
        res[product]++;
        highestScore = std::max(highestScore, product);
        return totalNodes;
    }

  public:
    int countHighestScoreNodes(std::vector<int> &parents) {
        int n = parents.size();
        adj.resize(n);
        for (int i = 0; i < n; ++i)
            if (parents[i] != -1) adj[parents[i]].push_back(i);
        long long highestScore = 0;
        countNodes(0, n, highestScore);
        return res[highestScore];
    }
};
