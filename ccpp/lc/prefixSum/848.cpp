#include <string>
#include <vector>

class Solution {
  public:
    std::string shiftingLetters(std::string s, std::vector<int> &shifts) {
        int n = shifts.size();
        long long acc = 0;
        for (int i = n - 1; i >= 0; --i) {
            acc = (acc + shifts[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;
        }
        return s;
    }
};