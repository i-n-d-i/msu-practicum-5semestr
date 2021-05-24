#include <iostream>
#include <vector>

struct TSegments {
    int size;
    std::vector<uint64_t> array;

    TSegments(int n);
    void Modify(int pos, int value);
    uint64_t SumOfSegment(int left, int right);
    void UpdateElem(std::vector<int> &a, int pos, int value);
};

TSegments::TSegments(int n)
    : size(n)
    , array(n, 0)
{}

void TSegments::Modify(int pos, int value) {
    while (pos < size) {
        array[pos] += value;
        pos = pos | (pos + 1);
    }
}

uint64_t TSegments::SumOfSegment(int left, int right) {
    uint64_t sum = 0;
	while (right >= 0) {
		sum += array[right];
		right = (right & (right + 1)) - 1;
	}
    left -= 1;
	while (left >= 0) {
		sum -= array[left];
		left = (left & (left + 1)) - 1;
	}
	return sum;
}

void TSegments::UpdateElem(std::vector<int> &a, int pos, int value) {
    int d = value - a[pos];
    a[pos] = value;
    Modify(pos, d);
}

int main() {
    int n, m;
    std::cin >> n;
    TSegments segments(n);
    std::vector<int> a(n);
    std::vector<uint64_t> answer;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        segments.Modify(i, a[i]);
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        char symbol;
        int num1, num2;
        std::cin >> symbol >> num1 >> num2;
        if (symbol == 's') {
            answer.push_back(segments.SumOfSegment(num1 - 1, num2 - 1));
        }
        if (symbol == 'u') {
            segments.UpdateElem(a, num1 - 1, num2);
        }
    }
    for (uint i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
