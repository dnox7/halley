#include <algorithm>
#include <vector>

class Solution {
  public:
    int buyChoco(std::vector<int> &prices, int money) {
        std::sort(prices.begin(), prices.end());
        if (prices[0] + prices[1] > money) return money;
        return money - prices[0] - prices[1];
    }
};
