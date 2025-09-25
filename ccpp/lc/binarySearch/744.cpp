#include <algorithm>
#include <vector>

class Solution {
  public:
    char nextGreatestLetter(std::vector<char> &letters, char target) {
        std::sort(letters.begin(), letters.end());
        int n = letters.size();
        int left = 0, right = n - 1;
        char res = letters[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                res = letters[mid];
                right = mid - 1;
            } else left = mid + 1;
        }
        return res;
    }
};
