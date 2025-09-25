#include <string>
#include <vector>

class Solution {
  public:
    bool scoreBalance(std::string s) {
        std::vector<int> arr;
        int n = s.size();
        arr.resize(n);

        arr[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; ++i) arr[i] = s[i] - 'a' + 1 + arr[i - 1];
        for (int i = 0; i < n; ++i) {
            if (arr[i] * 2 == arr[n - 1]) return true;
        }
        return false;
    }
};
