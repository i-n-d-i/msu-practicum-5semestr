#include <iostream>
#include <vector>


struct TSegments {
    std::vector<std::pair<uint32_t, uint32_t>> tree;      // first - add,   second - max

    TSegments(uint32_t n);
    void BuildTree(uint32_t *array, uint32_t vertex, uint32_t left, uint32_t right);
    uint32_t Maximum(uint32_t vertex, uint32_t left, uint32_t right, uint32_t a, uint32_t b, uint32_t add);
    void Update(uint32_t vertex, uint32_t left, uint32_t right, uint32_t a, uint32_t b, uint32_t value);
};

TSegments::TSegments(uint32_t n)
    : tree(4 * n, {0, 0})
{}


void TSegments::BuildTree(uint32_t *array, uint32_t vertex, uint32_t left, uint32_t right) {
    if (left == right) {
        tree[vertex].second = array[left];
        return;
    } else {
        uint32_t mid = (left + right) / 2;
        BuildTree(array, vertex * 2, left, mid);
        BuildTree(array, vertex * 2 + 1, mid + 1, right);
        tree[vertex].second = std::max(tree[vertex * 2].second, tree[vertex * 2 + 1].second);
    }
}

uint32_t TSegments::Maximum(uint32_t vertex, uint32_t left, uint32_t right, uint32_t a, uint32_t b, uint32_t add) {
    if (left > right) {
		return 0;
    }
	if (right < a || left > b) {
		return 0;
    }
    if (a <= left && right <= b) {
        return tree[vertex].second + tree[vertex].first + add;
    }
    uint32_t mid = (left + right) / 2;
    uint32_t leftMax = Maximum(vertex * 2, left, mid, a, std::min(b, mid), tree[vertex].first + add);
    uint32_t rightMax = Maximum(vertex * 2 + 1, mid + 1, right, std::max(a, mid + 1), b, tree[vertex].first + add);
	return std::max(leftMax, rightMax);
}

void TSegments::Update(uint32_t vertex, uint32_t left, uint32_t right, uint32_t a, uint32_t b, uint32_t value) {
    if (left > right) {
        return;
    }
    if (right < a || left > b) {
        return;
    }
    if (a <= left && right <= b) {
        tree[vertex].first += value;
        return;
    } else {
        uint32_t mid = (left + right) / 2;
        Update(vertex * 2, left, mid, a, std::min(b, mid), value);
        Update(vertex * 2 + 1, mid + 1, right, std::max(mid + 1, a), b, value);
        tree[vertex].second = std::max(tree[vertex * 2].second + tree[vertex * 2].first, tree[vertex * 2 + 1].second + tree[vertex * 2 + 1].first);
    }
}


int main() {
    uint32_t n, m, *array;
    std::cin >> n;
    TSegments segments(n);
    array = new uint32_t[n];
    for (uint32_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    segments.BuildTree(array, 1, 0, n - 1);
    std::cin >> m;
    for (uint32_t i = 0; i < m; i++) {
        char symbol;
        int a, b, num;
        std::cin >> symbol;
        if (symbol == 'm') {
            std::cin >> a >> b;
            std::cout << segments.Maximum(1, 0, n - 1, a - 1, b - 1, 0) << ' ';
        } else if (symbol == 'a') {
            std::cin >> a >> b >> num;
            segments.Update(1, 0, n - 1, a - 1, b - 1, num);
        }
    }
    std::cout << std::endl;
    return 0;
}
