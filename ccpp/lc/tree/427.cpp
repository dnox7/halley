#include "lc_tree.h"
#include <vector>

#define Node QuadTreeNode

class Solution {
  public:
    Node *construct(std::vector<std::vector<int>> &grid) {
        return build(0, 0, grid.size(), grid);
    }

    Node *build(int x, int y, int n, const std::vector<std::vector<int>> &grid) {
        if (isLeaf(x, y, n, grid)) {
            Node *leaf = new Node(grid[x][y], true);
            return leaf;
        }

        Node *node = new Node();
        node->topLeft = build(x, y, n / 2, grid);
        node->topRight = build(x, y + n / 2, n / 2, grid);
        node->bottomLeft = build(x + n / 2, y, n / 2, grid);
        node->bottomRight = build(x + n / 2, y + n / 2, n / 2, grid);
        return node;
    }

    bool isLeaf(int x, int y, int n, const std::vector<std::vector<int>> &grid) {
        int leafVal = grid[x][y];
        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + n; ++j) {
                if (grid[i][j] != leafVal) {
                    return false;
                }
            }
        }
        return true;
    }
};
