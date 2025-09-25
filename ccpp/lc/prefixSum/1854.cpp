#include <vector>

class Solution {
  public:
    int maximumPopulation(std::vector<std::vector<int>> &logs) {
        const int MAX = 101;
        int arr[MAX] = {0};
        for (const std::vector<int> &log : logs) {
            arr[log[0] - 1950] += 1;
            arr[log[1] - 1950] -= 1;
        }

        int res = 1950, maxPopulation = arr[0];
        for (int i = 1; i < MAX; ++i) {
            arr[i] += arr[i - 1];
            if (arr[i] > maxPopulation) {
                maxPopulation = arr[i];
                res = i + 1950;
            }
        }
        return res;
    }
};
