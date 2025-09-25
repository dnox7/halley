class Solution {
  public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long k = mid * mid;
            if (k == num) return true;
            else if (k > num) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
