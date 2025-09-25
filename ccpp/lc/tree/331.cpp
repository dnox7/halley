#include <string>
#include <vector>

class Solution {
  public:
    bool isValidSerialization(std::string preorder) {
        int n = preorder.size(), slot = 1;
        for (int i = 0; i < n; ++i) {
            if (preorder[i] == ',') {
                slot--;
                if (slot < 0) return false;
                if (preorder[i - 1] != '#') slot += 2;
            }
        }

        if (preorder[n - 1] == '#') slot--;
        else slot++;
        return slot == 0;
    }

    bool isValidSerialization1(std::string preorder) {
        std::vector<std::string> arr = split(preorder, ",");
        std::vector<std::string> stack;

        for (std::string &ele : arr) {
            stack.push_back(ele);
            while (stack.size() >= 3) {
                int n = stack.size();
                if (stack[n - 3] != "#" && stack[n - 2] == "#" &&
                    stack[n - 1] == "#") {
                    stack.erase(stack.end() - 3, stack.end() - 1);
                } else break;
            }
        }
        return stack.size() == 1 && stack[0] == "#";
    }

    std::vector<std::string> split(const std::string &s,
                                   const std::string &del) {
        std::vector<std::string> res;
        int start, end = -1 * del.size();
        do {
            start = end + del.size();
            end = s.find(del, start);
            res.push_back(s.substr(start, end - start));
        } while (end != -1);
        return res;
    }
};
