#include <unordered_map>

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        std::unordered_map<Node *, Node *> m;
        Node *curr = head;

        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node *newNode = m[curr];
            newNode->next = m[curr->next];
            newNode->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};
