#include <iostream>
#include <vector>
#include <set>
#include <cmath>

const uint64_t INF = 3e11;

class TGraph {
private:
    uint64_t VerticesNumber;
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> AdjacencyLists;

public:
    TGraph();
    TGraph(uint64_t n);
    void ReadFromStream(std::istream& stream, uint64_t k);
    int64_t Dijkstra(uint64_t a, uint64_t b) const;
};

TGraph::TGraph()
    : VerticesNumber(0)
    , AdjacencyLists()
{
}

TGraph::TGraph(uint64_t n)
    : VerticesNumber(n)
    , AdjacencyLists(n)
{
}


void TGraph::ReadFromStream(std::istream& stream, uint64_t k) {
    uint64_t u, v, cost;
    for (uint64_t i = 0; i < k; i++) {
        stream >> u >> v >> cost;
        AdjacencyLists[u - 1].push_back(std::make_pair(v - 1, cost));
        AdjacencyLists[v - 1].push_back(std::make_pair(u - 1, cost));
    }
}

int64_t TGraph::Dijkstra(uint64_t a, uint64_t b) const{
    std::vector<uint64_t> distance(VerticesNumber, INF);
    std::set<std::pair<uint64_t, uint64_t>> q;
    distance[a - 1] = 0;
    q.insert(std::make_pair(distance[a - 1], a - 1));
    while (!q.empty()) {
        uint64_t begin = q.begin()->second;
        q.erase(q.begin()); 
        for (uint64_t j = 0; j < AdjacencyLists[begin].size(); j++) {
            uint64_t to = AdjacencyLists[begin][j].first;
            uint64_t len = AdjacencyLists[begin][j].second;
            if (distance[begin] + len < distance[to]) {
                q.erase(std::make_pair(distance[to], to));
                distance[to] = distance[begin] + len;
                q.insert(std::make_pair(distance[to], to));
            }
        }
    }
    if (distance[b - 1] == INF) {
        return -1;
    } else {
        return distance[b - 1];
    }
}

int main() {
    uint64_t n, k, a, b;
    std::cin >> n >> k;
    TGraph graph(n);
    graph.ReadFromStream(std::cin, k);
    std::cin >> a >> b;
    std::cout << graph.Dijkstra(a, b) << std::endl;
    return 0;
}
