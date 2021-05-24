#include <iostream>
#include <vector>

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;

    bool DFS(uint32_t vertex, std::vector<uint32_t>& colors) const;
public:
    TGraph();
    TGraph(uint32_t N);
    void ReadFromStream(std::istream& stream);
    bool HasCycle() const;
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyMatrix()
{
}

TGraph::TGraph(uint32_t N)
    : VerticesNumber(N)
    , AdjacencyMatrix(N, std::vector<uint32_t>(N, 0))
{
}

bool TGraph::DFS(uint32_t vertex, std::vector<uint32_t>& colors) const {
    colors[vertex] = 1;
    for (uint32_t i = 0; i < VerticesNumber; ++i) {
        int elem = AdjacencyMatrix[vertex][i];
        if (elem == 1 && colors[i] == 0) {
            if (DFS(i, colors) == true) {
                return true;
            }
        } else if (elem == 1 && colors[i] == 1) {
            return true;
        }
    }
    colors[vertex] = 2;
    return false;
}

void TGraph::ReadFromStream(std::istream& stream) {
    uint32_t matrixElement;
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            stream >> matrixElement;
            AdjacencyMatrix[i][j] = matrixElement;
        }
    }
}

bool TGraph::HasCycle() const {
    std::vector<uint32_t> colors(VerticesNumber, 0);
    for (uint32_t i = 0; i < VerticesNumber; ++i) {
        if (DFS(i, colors)) {
           return true;
        }
    }
    return false; 
}

int main() {
    uint32_t N;
    std::cin >> N;

    TGraph graph(N);
    graph.ReadFromStream(std::cin);
    std::cout << graph.HasCycle() << std::endl;
    return 0;
}
