#include <algorithm>
#include <string>

class Solution {
  public:
    int minimumSum(int num) {
        auto s = std::to_string(num);
        std::sort(s.begin(), s.end());
        std::string num1 = "0", num2 = "0";
        bool flag;
        for (char c : s) {
            if (c != '0') {
                if (flag) num1.push_back(c);
                else num2.push_back(c);
                flag = !flag;
            }
        }
        return std::stoi(num1) + std::stoi(num2);
    }
};
