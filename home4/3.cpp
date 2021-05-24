#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> len(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> len[i];
    }
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += len[i] / mid;
        }
        if (sum >= k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    std::cout << left - 1 << std::endl;
    return 0;
}
