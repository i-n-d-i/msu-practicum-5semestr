#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    char lines[N + 2][M + 2];
    
    for (int j = 0; j <= M + 1; j++) {
        lines[0][j] = '.';
        lines[N + 1][j] = '.';
        lines[j][0] = '.';
        lines[j][N + 1] = '.';
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> lines[i][j];
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (lines[i - 1][j - 1] == '.' 
                && lines[i - 1][j] == '.' 
                && lines[i - 1][j + 1] == '.' 
                && lines[i - 1][j + 2] == '.' 
                && lines[i - 1][j + 3] == '.' 
                && lines[i][j + 3] == '.' 
                && lines[i + 1][j + 3] == '.'
                && lines[i + 2][j + 3] == '.'
                && lines[i + 3][j + 3] == '.' 
                && lines[i + 3][j + 2] == '.' 
                && lines[i + 3][j + 1] == '.'
                && lines[i + 3][j] == '.'
                && lines[i][j - 1] == '.' 
                && lines[i + 1][j - 1] == '.' 
                && lines[i + 2][j - 1] == '.'
                && lines[i + 3][j - 1] == '.'
                && lines[i][j] == '#' 
                && lines[i][j + 1] == '.' 
                && lines[i][j + 2] == '#' 
                && lines[i + 1][j] == '#' 
                && lines[i + 1][j + 1] == '#' 
                && lines[i + 1][j + 2] == '#' 
                && lines[i + 2][j] == '#'
                && lines[i + 2][j + 1] == '.'
                && lines[i + 2][j + 2] == '#') {
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
