#include <iostream>
#include <vector>

class TTree {
private:
    int32_t Size, l;
    int32_t Timer;
    std::vector<std::vector<int32_t>> Tree;
    std::vector<int32_t> Tin, Tout;
    std::vector<std::vector<int32_t>> Up;

public:
    TTree(int32_t n);
    void ReadTree(std::istream& stream);
    void DFS(int32_t vertex, int32_t num);
    bool Upper(int32_t a, int32_t b);
    int32_t LCA(int32_t a, int32_t b);
};

TTree::TTree(int32_t n)
    : Size(n)
    , l(1)
    , Timer(0)
    , Tree(n)
    , Tin(n)
    , Tout(n)
    , Up(n)
{}

void TTree::ReadTree(std::istream& stream) {
    for (int32_t i = 1; i < Size; ++i) {
        int32_t elem;
        stream >> elem;
        Tree[elem].push_back(i);
    }
    while ((1 << l) <= Size) {
        ++l;
    }
	for (int32_t i = 0; i < Size; ++i) {
        Up[i].resize(l + 1);
    }
}

void TTree::DFS(int32_t vertex, int32_t num) {
    Tin[vertex] = ++Timer;
    Up[vertex][0] = num;
	for (int32_t i = 1; i <= l; ++i) {
	   Up[vertex][i] = Up[Up[vertex][i - 1]][i - 1];
    }
    for (uint32_t i = 0; i < Tree[vertex].size(); ++i) {
        int32_t to = Tree[vertex][i];
	    if (to != num) {
	       DFS(to, vertex);
        }
    }
	Tout[vertex] = ++Timer;
}

bool TTree::Upper(int32_t a, int32_t b) {
	return Tin[a] <= Tin[b] && Tout[a] >= Tout[b];
}

int32_t TTree::LCA(int32_t a, int32_t b) {
	if (Upper(a, b)) {
        return a;
    }
	if (Upper(b, a)) {
        return b;
    }
	for (int32_t i = l; i >= 0; --i) {
		if (!Upper(Up[a][i], b)) {
			a = Up[a][i];
        }
    }
	return Up[a][0];
}

int main() {
    int32_t n, m, x, y, z, answer = 0;
    std::cin >> n >> m;

    TTree tree(n);
    tree.ReadTree(std::cin);

    std::vector<int32_t> a(2 * m + 1);
    std::cin >> a[1] >> a[2];
    std::cin >> x >> y >> z;
    for (int32_t i = 3; i <= 2 * m; ++i) {
        a[i] = (x * a[i - 2] + y * a[i - 1] + z) % n;
    }

	tree.DFS(0, 0);
    int32_t res = tree.LCA(a[1], a[2]);
    answer += res;
	for (int32_t i = 2; i <= m; ++i) {
        res = tree.LCA((a[2 * i - 1] + res) % n, a[2* i]);
        answer += res;
    }
    std::cout << answer << std::endl;
    return 0;
}
