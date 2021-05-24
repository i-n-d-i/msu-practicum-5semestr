#include <iostream>
#include <vector>
#include <algorithm>

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;
    std::vector<std::vector<uint32_t>> TransposedMatrix;
    
    void DFS1(uint32_t vertex, std::vector<bool>& visited, std::vector<uint32_t>& order) const;
    void DFS2(uint32_t vertex, std::vector<bool>& visited, std::vector<uint32_t>& component) const;
public:
    TGraph();
    TGraph(uint32_t n);
    void ReadFromStream(std::istream& stream, uint32_t m);
    void Condens(std::vector<uint32_t>& answer, uint32_t& number) const;
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyMatrix()
    , TransposedMatrix()
{
}

TGraph::TGraph(uint32_t n)
    : VerticesNumber(n)
    , AdjacencyMatrix(n, std::vector<uint32_t>(0, 0))
    , TransposedMatrix(n, std::vector<uint32_t>(0, 0))
{
}

void TGraph::ReadFromStream(std::istream& stream, uint32_t m) {
    uint32_t i, j;
    for (uint32_t k = 0; k < m; ++k) {
        stream >> i >> j;
        AdjacencyMatrix[i - 1].push_back(j - 1);
        TransposedMatrix[j - 1].push_back(i - 1);
    }
}



void TGraph::DFS1(uint32_t vertex, std::vector<bool>& visited, std::vector<uint32_t>& order) const {
    visited[vertex] = 1;
    for (uint32_t i = 0; i < AdjacencyMatrix[vertex].size(); ++i) {
        int to = AdjacencyMatrix[vertex][i];
        if (!visited[to]) {
            DFS1(to, visited, order);
        }
    }
    order.push_back(vertex);
}

void TGraph::DFS2(uint32_t vertex, std::vector<bool>& visited, std::vector<uint32_t>& component) const {
    visited[vertex] = 1;
    component.push_back(vertex);
    for (uint32_t i = 0; i < TransposedMatrix[vertex].size(); ++i) {
        int to = TransposedMatrix[vertex][i];
        if (!visited[to]) {
            DFS2(to, visited, component);
        }
    }
}

    
void TGraph::Condens(std::vector<uint32_t>& answer, uint32_t& number) const {
    std::vector<uint32_t> order;
    std::vector<bool> visited(VerticesNumber, false);
    for (uint32_t i = 0; i < VerticesNumber; ++i) {
        if (!visited[i]) {
            DFS1(i, visited, order);
        }
    }
    visited.assign(VerticesNumber, false);
    for (uint32_t i = 0; i < VerticesNumber; ++i) {
        std::vector<uint32_t> component;
        uint32_t elem = order[VerticesNumber - 1 - i];
        if (!visited[elem]) {
            DFS2(elem, visited, component);
            number++;
            for (uint32_t m = 0; m < component.size(); ++m) {
                uint32_t num = component[m];
                answer[num] = number;
            }
        }
    }
}


int main() {
    uint32_t n, m, number = 0;
    std::cin >> n >> m;
    std::vector<uint32_t> answer(n);
    TGraph graph(n);
    graph.ReadFromStream(std::cin, m);
    graph.Condens(answer, number); 
    std::cout << number << std::endl;
    for (uint32_t i = 0; i < n; ++i) {
        std::cout << answer[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
