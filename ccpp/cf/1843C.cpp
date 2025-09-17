#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long res = n;
        while (n != 1) {
            n /= 2;
            res += n;
        }
        std::cout << res << '\n';
    }
    return 0;
}
