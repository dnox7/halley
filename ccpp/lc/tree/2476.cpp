#include "lc_tree.h"

class Solution {
  private:
    void dfs(TreeNode *curr, std::vector<int> &sorted) {
        if (!curr) return;
        dfs(curr->left, sorted);
        sorted.push_back(curr->val);
        dfs(curr->right, sorted);
    }

    std::vector<int> binarySearch(int target, int n, const std::vector<int> &arr) {
        int left = 0, right = n - 1;
        int pos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                pos = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        if (pos < n && arr[pos] == target) return {target, target};
        int smaller = -1, larger = -1;
        if (pos > 0) smaller = arr[pos - 1];
        if (pos < n) larger = arr[pos];
        return {smaller, larger};
    }

  public:
    std::vector<std::vector<int>> closestNodes(TreeNode *root, std::vector<int> &queries) {
        std::vector<int> sorted;
        dfs(root, sorted);

        int n = sorted.size();
        std::vector<std::vector<int>> res;
        for (int &query : queries) res.push_back(binarySearch(query, n, sorted));
        return res;
    }
};
