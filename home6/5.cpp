#include <iostream>
#include <vector>

class Tree {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;

public:
    Tree();
    Tree(uint32_t n);
    void AddVertice(uint32_t a, uint32_t b);
//    uint32_t GetLCA(uint32_t a, uint32_t b);
    void PrintTree();
};

Tree::Tree()
    : VerticesNumber(0)
    , AdjacencyMatrix()
{}

Tree::Tree(uint32_t n)
    : VerticesNumber(n)
    , AdjacencyMatrix(INT8_MAX, std::vector<uint32_t>(0))
{}

void Tree::AddVertice(uint32_t a, uint32_t b) {
    if (b > a) {
        VerticesNumber = b;
    }
    AdjacencyMatrix[a].push_back(b);
}

void Tree::PrintTree() {
    for (uint32_t i = 0; i <= VerticesNumber; ++i) {
        for (uint32_t j = 0; j < AdjacencyMatrix[i].size(); ++j) {
            std::cout << i << ':'<< AdjacencyMatrix[i][j] << ' ';
        }
        std::cout << std:: endl;
    }
}

int main() {
    uint32_t k, n = 1;
    std::cin >> k;
    Tree tree(n);
    for (uint32_t i = 0; i < k; ++i) {
        std::string sym;
        uint32_t a, b;
        std::cin >> sym >> a >> b;
        if (sym == "ADD") {
            tree.AddVertice(a, b);
        }
        if (sym == "GET") {
            std::cout << "Hello" << std::endl;
        }
    }
    tree.PrintTree();
    return 0;
}
