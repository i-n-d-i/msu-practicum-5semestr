#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> distance(m + 1, std::vector<int>(n + 1, 0));
    distance[0][0] = 0;
    for (int j = 1; j <= n; j++) {
        distance[0][j] = distance[0][j - 1] + 1;
    }
    for (int i = 1; i <= m; i++) {
        distance[i][0] = distance[i - 1][0] + 1;
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] != s2[j - 1]) {
                distance[i][j] = std::min(distance[i - 1][j] + 1, distance[i][j - 1] + 1);
                distance[i][j] = std::min(distance[i][j], distance[i - 1][j - 1] + 1);
            } else {
                distance[i][j] = distance[i - 1][j - 1];
            }
        }
    }
    std::cout << distance[m][n] << std::endl;
    return 0;
}
