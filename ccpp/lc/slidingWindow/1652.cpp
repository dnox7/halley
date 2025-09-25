#include <cstdlib>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<int> decrypt1(std::vector<int> &code, int k) {
        int n = code.size();
        if (k == 0) return std::vector<int>(n, 0);
        bool flag = k > 0;
        k = std::abs(k);

        std::vector<int> res;

        int total = std::accumulate(code.begin() + 1, code.begin() + k + 1, 0);
        res.push_back(total);
        for (int i = 1; i < n; ++i) {
            int lastIdx = i < (n - k) ? (i + k) : (i + k - n);
            total += code[lastIdx] - code[i];
            res.push_back(total);
        }

        if (flag) return res;
        std::vector<int> res2;
        res2.insert(res2.end(), res.end() - k - 1, res.end());
        res2.insert(res2.end(), res.begin(), res.end() - k - 1);
        return res2;
    }
};
