#include <iostream>
#include <vector>

#define INF 101

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<int32_t>> AdjacencyMatrix;

public:
    TGraph();
    TGraph(uint32_t N);
    void Floyd();
    void ReadFromStream(std::istream& stream);
    void PrintMatrix(std::ostream& stream);
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyMatrix()
{
}

TGraph::TGraph(uint32_t N)
    : VerticesNumber(N)
    , AdjacencyMatrix(N, std::vector<int32_t>(N, 0))
{
}

void TGraph::Floyd() {
    for (uint32_t k = 0; k < VerticesNumber; ++k) {
        for (uint32_t i = 0; i < VerticesNumber; ++i) {
            for (uint32_t j = 0; j < VerticesNumber; ++j) {
                if (AdjacencyMatrix[i][k] < INF && AdjacencyMatrix[k][j] < INF) {
                    AdjacencyMatrix[i][j] = std::min(AdjacencyMatrix[i][j], AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j]);
                }
            }
        }
    }
}
        
void TGraph::PrintMatrix(std::ostream& stream) {
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            stream << AdjacencyMatrix[i][j] << ' ';
        }
        stream << '\n';
    }
}

void TGraph::ReadFromStream(std::istream& stream) {
    int32_t matrixElement;
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            stream >> matrixElement;
            AdjacencyMatrix[i][j] = matrixElement;
        }
    }
}


int main() {
    uint32_t n;
    std::cin >> n;

    TGraph graph(n);
    graph.ReadFromStream(std::cin);
    graph.Floyd();
    graph.PrintMatrix(std::cout);
    return 0;
}
