#include <vector>

class Solution {
  public:
    int maximizeSum(std::vector<int> &nums, int k) {
        int maxScore = 0;
        int maxNum = -1;
        for (int num : nums) {
            if (num > maxNum) {
                maxNum = num;
            }
        }
        while (k > 0) {
            maxScore += maxNum;
            maxNum++;
            k--;
        }
        return maxScore;
    }
};
