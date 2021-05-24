#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    std::vector<int> distance(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
    distance[0] = 0;
    distance[1] = abs(array[1] - array[0]);
    for (int i = 2; i <= n; i++) {
         distance[i] = std::min(distance[i - 1], distance[i - 2]) + abs(array[i - 1] - array[i - 2]);
    }
    std::cout << distance[n] << std::endl;
    return 0;
}
