#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int N, answer = 0;
    cin >> N;
    vector<long long int> vector(N);
    for (long long int i = 0; i < N; i++) {
        cin >> vector[i];
        answer += vector[i];
    }
    long long int L = 0, R = answer, M;
    for (long long int i = 0; i < N - 1; i++) {
        L += vector[i];
        R -= vector[i];
        M = max(L, R);
        if (M < answer) {
            answer = M;
        }
    }
    cout << answer << endl;
    return 0;
}
