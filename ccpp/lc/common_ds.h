#ifndef LC_COMMON_DS_H
#define LC_COMMON_DS_H

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#endif // LC_COMMON_DS_H
