#include <iostream>
#include <vector>
#include <queue>

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;
    std::vector<uint32_t> Exits;
public:
    TGraph();
    TGraph(uint32_t N);
    void ReadExits(std::istream& stream, uint32_t K);
    void ReadTunnels(std::istream& stream, uint32_t M);
    std::vector<uint32_t> BFS(const std::vector<uint32_t>& startVertices) const; 
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyMatrix()
    , Exits()
{
}

TGraph::TGraph(uint32_t N)
    : VerticesNumber(N)
    , AdjacencyMatrix(N, std::vector<uint32_t>(0, 0))
    , Exits(N, 0)
{
}

void TGraph::ReadExits(std::istream& stream, uint32_t K) {
    std::vector<uint32_t> array(K);
    for (uint32_t i = 0; i < K; ++i) {
        stream >> array[i];
        uint32_t exit = array[i];
        Exits[exit - 1] = 1;
    }
}

void TGraph::ReadTunnels(std::istream& stream, uint32_t M) {
    uint32_t i, j;
    for (uint32_t k = 0; k < M; ++k) {
        stream >> i >> j;
        AdjacencyMatrix[i - 1].push_back(j - 1);
        AdjacencyMatrix[j - 1].push_back(i - 1);
    }
}

std::vector<uint32_t> TGraph::BFS(const std::vector<uint32_t>& startVertices) const {
    std::vector<uint32_t> answer(VerticesNumber, 0);
    std::vector<uint32_t> minimum(VerticesNumber, VerticesNumber);
    std::queue<uint32_t> q;
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        std::vector<bool> visited(VerticesNumber, false);
        uint32_t vertex = startVertices[i];
        if (Exits[vertex] == 1) {
            minimum[vertex] = 0;
            q.push(vertex);
            visited[vertex] = true;
            while (!q.empty()) {
                uint32_t v = q.front();
                q.pop();
                for (uint32_t j = 0; j < AdjacencyMatrix[v].size(); ++j) {
                    uint32_t to = AdjacencyMatrix[v][j];
                    if (Exits[to] == 1) {
                        visited[to] = true;
                    }
                    if (!visited[to]) {
                        visited[to] = true;
                        q.push(to);
                        answer[to] = answer[v] + 1;
                        if (answer[to] < minimum[to]) {
                            minimum[to] = answer[to];
                        }
                    } 
                }
            }
        }
    }
    return minimum;
}


int main() {
    uint32_t N, K, M;
    std::cin >> N;
    TGraph graph(N);
    std::vector<uint32_t> startVertices(N), answer(N);
    std::cin >> K;
    graph.ReadExits(std::cin, K);
    std::cin >> M;
    graph.ReadTunnels(std::cin, M);
    
    for (uint32_t i = 0; i < N; i++) {
        startVertices[i] = i;
    }
    answer = graph.BFS(startVertices);
    for (uint32_t i = 0; i < N; i++) {
        std::cout << answer[i] << ' ';
    }
    return 0;
}
