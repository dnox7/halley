#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::string s;
    std::cin >> n >> q >> s;

    std::vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (s[i - 1] - 'a') + 1;
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        long long ans = dp[r] - dp[l - 1];
        std::cout << ans << '\n';
    }
    return 0;
}
