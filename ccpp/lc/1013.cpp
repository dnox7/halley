#include <numeric>
#include <vector>

class Solution {
  public:
    bool canThreePartsEqualSum(std::vector<int> &arr) {
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }

        int left = 0, right = arr.size() - 1, avg = sum / 3;
        int leftSum = arr[left++], rightSum = arr[right--];
        do {
            if (leftSum != avg) leftSum += arr[left++];
            if (left < right && rightSum != avg) rightSum += arr[right--];
            if (left <= right && leftSum == avg && rightSum == avg) return true;

        } while (left < right);
        return false;
    }
};
