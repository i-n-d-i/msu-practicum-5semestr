#include <iostream>

using namespace std;

int main() {
    int N, D = 0, C = 0;
    int spoons = 2;
    cin >> N;
    while (N - spoons >= 0) {
        D++;
        N -= spoons;
        spoons *= 2;
    }
    if (N != 0) {
        C = spoons - N;
    }
    cout << D << ' ' << C << endl;
    return 0;
}
