#ifndef LC_TREE_H
#define LC_TREE_H

#include <cstddef>
#include <vector>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int v) : val(v) {}

    Node(int v, std::vector<Node *> c) : val(v), children(c) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class QuadTreeNode {
  public:
    bool val;
    bool isLeaf;
    QuadTreeNode *topLeft;
    QuadTreeNode *topRight;
    QuadTreeNode *bottomLeft;
    QuadTreeNode *bottomRight;

    QuadTreeNode() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    QuadTreeNode(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    QuadTreeNode(bool _val, bool _isLeaf, QuadTreeNode *_topLeft, QuadTreeNode *_topRight, QuadTreeNode *_bottomLeft, QuadTreeNode *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

#endif // LC_TREE_H
