#include <iostream>
#include <vector>

struct TSegments {
    std::vector<int64_t> array;

    TSegments(int64_t n);
    int64_t Sum(int64_t a, int64_t b);
    void BuildTree(int64_t *a, int64_t vertex, int64_t left, int64_t right);
    int64_t SumOfSegment(int64_t vertex, int64_t left, int64_t right, int64_t a, int64_t b);
    void UpdateElem(int64_t vertex, int64_t left, int64_t right, int64_t pos, int64_t value);
};

TSegments::TSegments(int64_t n)
    : array(n * 4, 0)
{}

int64_t TSegments::Sum(int64_t a, int64_t b) {
    if (a == -1) {
        return b;
    } else if (b == -1) {
        return a;
    } else {
        return a + b;
    }
}

void TSegments::BuildTree(int64_t *a, int64_t vertex, int64_t left, int64_t right) {
    if (left == right) {
        array[vertex] = a[left];
    } else {
        int64_t mid = (left + right) / 2;
        BuildTree(a, vertex * 2, left, mid);
        BuildTree(a, vertex * 2 + 1, mid + 1, right);
        array[vertex] = Sum(array[vertex * 2], array[vertex * 2 + 1]);
    }
}

int64_t TSegments::SumOfSegment(int64_t vertex, int64_t left, int64_t right, int64_t a, int64_t b) {
    if (a > b) {
        return -1;
    }
    if (a == left && b == right) {
        return array[vertex];
    }
    int64_t mid = (left + right) / 2;
    return Sum(SumOfSegment(vertex * 2, left, mid, a, std::min(b, mid)),
               SumOfSegment(vertex * 2 + 1, mid + 1, right, std::max(a, mid + 1), b));
}

void TSegments::UpdateElem(int64_t vertex, int64_t left, int64_t right, int64_t pos, int64_t value) {
    if (left == right) {
		array[vertex] = value;
    } else {
    	int64_t mid = (left + right) / 2;
        if (pos <= mid) {
            UpdateElem(vertex * 2, left, mid, pos, value);
        } else {
    	    UpdateElem(vertex * 2 + 1, mid + 1, right, pos, value);
        }
    	array[vertex] = Sum(array[vertex * 2], array[vertex * 2 + 1]);
    }
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
        char symbol;
        uint64_t num1, num2;
        std::cin >> symbol >> num1 >> num2;
        if (symbol == 's') {
            std::cout << segments.SumOfSegment(1, 0, n - 1, num1 - 1, num2 - 1) << ' ';
        }
        if (symbol == 'u') {
            segments.UpdateElem(1, 0, n - 1, num1 - 1, num2);
        }
    }
    delete [] a;
    std::cout << std::endl;
    return 0;
}
