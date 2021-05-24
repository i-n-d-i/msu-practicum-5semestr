#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, k, a = 1000000007;
    cin >> N >> k;
    vector<int> vector(N + 1);
    for (int i = 0; i < k; i++) {
        vector[i] = 1;
    }
    for (int i = k; i <= N; i++) {
        int m = 1;
        while (m <= k) {
            vector[i] += vector[i - m];
            vector[i] %= a;
            m++;
        }
    }
    cout << vector[N] << endl;
    return 0;
}
