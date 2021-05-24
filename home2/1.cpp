#include <iostream>
#include <vector>
#include <stack>

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::vector<uint32_t>> AdjacencyMatrix;
public:
    TGraph();
    TGraph(uint32_t N);
    void ReadFromStream(std::istream& stream);
    uint32_t ConnectedComponentsNumber(const uint32_t S) const;
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

void TGraph::ReadFromStream(std::istream& stream) {
    uint32_t matrixElement;
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            stream >> matrixElement;
            AdjacencyMatrix[i][j] = matrixElement;
        }
    }
}

uint32_t TGraph::ConnectedComponentsNumber(const uint32_t S) const {
    uint32_t answer = 0, vertex;
    std::stack<uint32_t> stack;
    std::vector<bool> passedVertex(VerticesNumber, false);
    stack.push(S);
    passedVertex[S] = true;
    while (stack.empty() != true) {
        vertex = stack.top();
        stack.pop();
        answer++;
        for (uint32_t i = 0; i < VerticesNumber; i++) {
            if (AdjacencyMatrix[vertex][i] == 1 && passedVertex[i] == false) {
                stack.push(i);
                passedVertex[i] = true;
            }
        }
    }
    return answer;
}


int main() {
    uint32_t N, S;
    std::cin >> N >> S;

    TGraph graph(N);
    graph.ReadFromStream(std::cin);
    std::cout << graph.ConnectedComponentsNumber(S - 1) << std::endl;
    return 0;
}
