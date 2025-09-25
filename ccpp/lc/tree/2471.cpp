#include "lc_tree.h"
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  private:
    int countSteps(int n, std::vector<int> &arr) {
        std::vector<int> sorted(arr);
        std::sort(sorted.begin(), sorted.end());

        std::unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) pos[arr[i]] = i;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != sorted[i]) res++;
            int currPos = pos[sorted[i]];
            pos[arr[i]] = currPos;
            std::swap(arr[currPos], arr[i]);
        }
        return res;
    }

  public:
    int minimumOperations(TreeNode *root) {
        int res = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            std::vector<int> level;
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res += countSteps(n, level);
        }
        return res;
    }
};
