#include "lc_tree.h"
#include <string>

class Codec {
  public:
    std::string serialize(TreeNode *root) {
        std::string res;
        buildStr(root, res);
        if (!res.empty()) res.pop_back();
        return res;
    }

    void buildStr(TreeNode *root, std::string &res) {
        if (!root) return;
        res += (std::to_string(root->val)) + ",";
        buildStr(root->left, res);
        buildStr(root->right, res);
    }

    TreeNode *deserialize(std::string data) {
        std::vector<int> preorder = split(data, ",");
        return constructTree(0, preorder.size(), preorder);
    }

    TreeNode *constructTree(int start, int end, const std::vector<int> &preorder) {
        if (start >= end) return nullptr;
        int i = start + 1;
        while (i < end && preorder[i] < preorder[start]) i++;
        TreeNode *root = new TreeNode(preorder[start]);
        root->left = constructTree(start + 1, i, preorder);
        root->right = constructTree(i, end, preorder);
        return root;
    }

    std::vector<int> split(const std::string &s, const std::string &del) {
        std::vector<int> res;
        if (s.empty()) return res;
        int start, end = -1 * del.size();
        do {
            start = end + del.size();
            end = s.find(del, start);
            res.push_back(std::stoi(s.substr(start, end - start)));
        } while (end != -1);
        return res;
    }
};
