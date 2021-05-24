#include <iostream>
#include <vector>


uint32_t MaxCost(uint32_t n, uint32_t m, std::vector<uint32_t> mass, std::vector<uint32_t> cost) {
    std::vector<std::vector<uint32_t>> matrix(n + 1, std::vector<uint32_t>(m + 1, 0));
    uint32_t answer = 0;

    for (uint32_t i = 1; i < n + 1; ++i) {
        for (uint32_t j = 0; j < m + 1; ++j) {
            matrix[i][j] = matrix[i - 1][j];
            if (mass[i - 1] <= j) {
                matrix[i][j] = std::max(matrix[i][j], matrix[i - 1][j - mass[i - 1]] + cost[i - 1]);
            }
        }
    }
    for (uint32_t j = 0; j < m + 1; ++j) {
        if (matrix[n][j] > answer) {
            answer = matrix[n][j];
        }
    }
    return answer;
}

int main() {
    uint32_t n, m;
    std::cin >> n >> m;
    std::vector<uint32_t> mass(n), cost(n);
    for (uint32_t i = 0; i < n; ++i) {
        std::cin >> mass[i];
    }
    for (uint32_t i = 0; i < n; ++i) {
        std::cin >> cost[i];
    }
    std::cout << MaxCost(n, m, mass, cost) << std::endl;
    return 0;
}
