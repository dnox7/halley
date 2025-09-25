#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
  public:
    std::vector<int> pathInZigZagTree(int label) {
        std::vector<int> res;
        res.push_back(label);

        int level = log2(label) + 1;
        int parent = label;
        while (parent != 1) {
            parent = findParent(parent, level);
            res.push_back(parent);
            level--;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    int findParent(int node, int level) {
        if (level % 2 == 0) node = (1 << (level - 1)) + (1 << level) - 1 - node;
        int parent = node / 2;
        if (level % 2 != 0) {
            parent = (1 << (level - 2)) + (1 << (level - 1)) - 1 - parent;
        }
        return parent;
    }
};
