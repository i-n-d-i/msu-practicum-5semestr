#include <iostream>
#include <vector>
#include <algorithm>

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;

    bool DFS(uint32_t vertex, std::vector<uint32_t>& colors, std::vector<uint32_t>& answer) const;
public:
    TGraph();
    TGraph(uint32_t n);
    void ReadFromStream(std::istream& stream, uint32_t m);
    bool TopSort(std::vector<uint32_t>& answer) const;
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyMatrix()
{
}

TGraph::TGraph(uint32_t n)
    : VerticesNumber(n)
    , AdjacencyMatrix(n, std::vector<uint32_t>(0, 0))
{
}

void TGraph::ReadFromStream(std::istream& stream, uint32_t m) {
    uint32_t i, j;
    for (uint32_t k = 0; k < m; ++k) {
        stream >> i >> j;
        AdjacencyMatrix[i - 1].push_back(j - 1);
    }
}

bool TGraph::TopSort(std::vector<uint32_t>& answer) const {
    std::vector<uint32_t> colors(VerticesNumber, 0);
    for (uint32_t i = 0; i < VerticesNumber; ++i) {
        if (colors[i] == 0 && DFS(i, colors, answer)) {
            return true;
        }
    }
    std::reverse(answer.begin(), answer.end());
    return false;
}


bool TGraph::DFS(uint32_t vertex, std::vector<uint32_t>& colors, std::vector<uint32_t>& answer) const {
    colors[vertex] = 1;
    for (uint32_t i = 0; i < AdjacencyMatrix[vertex].size(); ++i) {
        int to = AdjacencyMatrix[vertex][i];
        if (colors[to] == 0) {
            if (DFS(to, colors, answer)) {
                return true;
            }
        } else if (colors[to] == 1) {
            return true;
        }
    }
    answer.push_back(vertex + 1);
    colors[vertex] = 2;
    return false;
}


int main() {
    uint32_t n, m;
    std::cin >> n >> m;
    TGraph graph(n);
    graph.ReadFromStream(std::cin, m);
    
    std::vector<uint32_t> answer(n);
    
    if (graph.TopSort(answer)) {
        std::cout << "No" << std::endl;
        return 0;
    } else {
        std::cout << "Yes" << std::endl;
        for (uint32_t i = 0; i < n; i++) {
            std::cout << answer[i] << ' ';
        }
    }
    return 0;
}
