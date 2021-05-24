#include <iostream>
#include <vector>
#include <algorithm>

class TDisjointSetUnion {
private:
    uint32_t VerticesNumber;
    mutable std::vector<uint32_t> Parent;
    std::vector<uint32_t> Size;
        
public:
    TDisjointSetUnion();
    TDisjointSetUnion(uint32_t n);
    void MakeSet();
    uint32_t FindSet(uint32_t vertice) const;
    void UnionSets(uint32_t a, uint32_t b); 
    uint32_t SizeOfSet(uint32_t vertice);
};


TDisjointSetUnion::TDisjointSetUnion()    
    : VerticesNumber(0)
    , Parent()
    , Size() 
{
}

TDisjointSetUnion::TDisjointSetUnion(uint32_t n)    
    : VerticesNumber(n)
    , Parent(n)
    , Size(n, 1)
{
}

uint32_t TDisjointSetUnion::FindSet(uint32_t vertice) const {
    if (vertice == Parent[vertice]) {
        return vertice;
    } else {
        return Parent[vertice] = FindSet(Parent[vertice]);
    }
}

void TDisjointSetUnion::UnionSets(uint32_t a, uint32_t b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (Size[a] == Size[b]) {
            Parent[a] = b;
            Size[b] += Size[a];
            Size[a] = Size[b];
        } else {
            if (Size[a] < Size[b]) {
                std::swap(a, b);
            }
            Parent[b] = a;
            Size[b] += Size[a];
            Size[a] = Size[b];
        }
    }
}

uint32_t TDisjointSetUnion::SizeOfSet(uint32_t vertice) {
    return Size[Parent[vertice]];
}

void TDisjointSetUnion::MakeSet() {
    for (uint32_t i = 0; i < VerticesNumber; i++) {
        Parent[i] = i;
    }
}

int main() {
    uint32_t n, m, answer = 0, a, b;
    std::cin >> n >> m;
    TDisjointSetUnion set(n);
    set.MakeSet();
    for (uint32_t i = 0; i < m; i++) {
        std::cin >> a >> b;
        answer++;
        set.UnionSets(a, b);
        if (set.SizeOfSet(0) == n) {
            break;
        }
    }
    std::cout << answer << std::endl;
    return 0;
}
