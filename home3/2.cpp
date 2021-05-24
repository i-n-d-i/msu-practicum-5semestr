#include <iostream>
#include <vector>
#include <cmath>

const float INF = 1000000001.0;

class TGraph {
private:
    uint32_t VerticesNumber;
    std::vector<std::pair<uint32_t, uint32_t>> Cities;
    std::vector<std::vector<std::pair<uint32_t, uint32_t>>> SpecialCities;

public:
    TGraph();
    TGraph(uint32_t n);
    void ReadFromStream(std::istream& stream);
    void ReadSpecialCities(std::istream& stream, uint32_t m);
    float Dijkstra(uint32_t a, uint32_t b);
};

TGraph::TGraph()
    : VerticesNumber(0)
    , Cities()
    , SpecialCities()
{
}

TGraph::TGraph(uint32_t n)
    : VerticesNumber(n)
    , Cities(n, std::pair<uint32_t, uint32_t>(0,0))
    , SpecialCities(n, std::vector<std::pair<uint32_t, uint32_t>>())
{
}


void TGraph::ReadFromStream(std::istream& stream) {
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        stream >> Cities[i].first >> Cities[i].second;
    }
}

void TGraph::ReadSpecialCities(std::istream& stream, uint32_t m) {
    uint32_t u, v, cost;
    for (uint32_t i = 0; i < m; i++) {
        stream >> u >> v >> cost;
        SpecialCities[u - 1].push_back(std::make_pair(v - 1, cost));
        SpecialCities[v - 1].push_back(std::make_pair(u - 1, cost));
    }
}

float TGraph::Dijkstra(uint32_t a, uint32_t b) {
    std::vector<float> distance(VerticesNumber, INF);
    std::vector<bool> visited(VerticesNumber, false);
    distance[a - 1] = 0;
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        int32_t v = -1;
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            if (!visited[j] && (v == -1 || distance[j] < distance[v])) {
                v = j;
            }
        }
        visited[v] = true;
        for (uint32_t j = 0; j < VerticesNumber; j++) {
            uint32_t flag = 0;
            for (uint32_t k = 0; k < SpecialCities[v].size(); k++) {
                if (SpecialCities[v][k].first == j) {
                    flag = 1;
                    if (!visited[j] && distance[v] + SpecialCities[v][k].second < distance[j]) {
                        distance[j] = distance[v] + SpecialCities[v][k].second;
                    }
                    break;
                }
            }
            if (!flag) {
                float cost = sqrt(pow(abs(Cities[v].first - Cities[j].first), 2) + pow(abs(Cities[v].second - Cities[j].second), 2));
                if (!visited[j] && distance[v] + cost  < distance[j]) {
                    distance[j] = distance[v] + cost;
                }
            }
        }
    }
    return distance[b - 1];
}

int main() {
    uint32_t n, m, a, b;
    std::cin >> n;
    TGraph graph(n);
    graph.ReadFromStream(std::cin);
    
    std::cin >> m;
    graph.ReadSpecialCities(std::cin, m);
    
    std::cin >> a >> b;
    std::cout << graph.Dijkstra(a, b) << std::endl;
    return 0;
}
