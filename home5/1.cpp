#include <iostream>
#include <vector>

struct TSegments {
    std::vector<std::pair<int64_t, int64_t>> array;

    TSegments(int64_t n);
    std::pair<int64_t, int64_t> MakePair(std::pair<int64_t, int64_t> a, std::pair<int64_t, int64_t> b);
    void BuildTree(int64_t *a, int64_t vertex, int64_t left, int64_t right);
    std::pair<int64_t, int64_t> Maximum(int64_t vertex, int64_t left, int64_t right, int64_t a, int64_t b);
};

TSegments::TSegments(int64_t n)
    : array(4 * n, {0, 0})
{}

std::pair<int64_t, int64_t> TSegments::MakePair(std::pair<int64_t, int64_t> a, std::pair<int64_t, int64_t> b) {
    if (a.first == -1) {
        return b;
    } else if (b.first == -1) {
        return a;
    } else if (a.second > b.second) {
        return a;
    } else {
        return b;
    }
}

void TSegments::BuildTree(int64_t *a, int64_t vertex, int64_t left, int64_t right) {
    if (left == right) {
        array[vertex] = std::make_pair(left, a[left]);
    } else {
        int64_t mid = (left + right) / 2;
        BuildTree(a, vertex * 2, left, mid);
        BuildTree(a, vertex * 2 + 1, mid + 1, right);
        array[vertex] = MakePair(array[vertex * 2], array[vertex * 2 + 1]);
    }
}

std::pair<int64_t, int64_t> TSegments::Maximum(int64_t vertex, int64_t left, int64_t right, int64_t a, int64_t b) {
    if (a > b) {
        return std::make_pair(-1, -1);
    }
    if (a == left && b == right) {
        return array[vertex];
    }
    int64_t mid = (left + right) / 2;
    return MakePair(Maximum(vertex * 2, left, mid, a, std::min(b, mid)),
                    Maximum(vertex * 2 + 1, mid + 1, right, std::max(a, mid + 1), b));
}


int main() {
    int64_t n, m, *a;
    std::cin >> n;
    a = new int64_t[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    TSegments segments(n);
    segments.BuildTree(a, 1, 0, n - 1);
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int64_t num1, num2;
        std::cin >> num1 >> num2;
        std::cout << segments.Maximum(1, 0, n - 1, num1 - 1, num2 - 1).first + 1 << ' ';
    }
    delete [] a;
    std::cout << std::endl;
    return 0;
}
