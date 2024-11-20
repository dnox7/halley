#include <algorithm>
#include <string>

class Solution {
  public:
    int splitNum(int num) {
        auto s = std::to_string(num);
        std::sort(s.begin(), s.end());

        int a = 0, b = 0;
        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';
            if (i & 1) a *= 10, a += digit;
            else b *= 10, b += digit;
        }
        return a + b;
    }
};
