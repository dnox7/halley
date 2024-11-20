#include <algorithm>
#include <string>

class Solution {
  public:
    int minMaxDifference(int num) {
        auto s = std::to_string(num), min = s, max = s;

        char c = min[0];
        std::replace(min.begin(), min.end(), c, '0');

        for (int i = 0; i < max.size(); i++) {
            if (max[i] != '9') {
                c = max[i];
                std::replace(max.begin(), max.end(), c, '9');
                break;
            }
        }

        return std::stoi(max) - std::stoi(min);
    }
};
