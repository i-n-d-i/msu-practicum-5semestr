#include <iostream>
#include <vector>

class TMagicSquare {
private:
    int Size;
    int TargetSum;
    std::vector<int> Array;
    std::vector<int> ColumnSum;
    std::vector<int> RowSum;

public:
    TMagicSquare(int n);
    void ReadArray(std::istream& stream);
    bool IsMagicSquare(int i, int j);
    bool Permutation(int elem);
    void Solve();
};

TMagicSquare::TMagicSquare(int n)
    : Size(n)
    , TargetSum(0)
    , Array(n)
    , ColumnSum(n / 4)
    , RowSum(n / 4)
{}

void TMagicSquare::ReadArray(std::istream& stream) {
    for (int i = 0; i < Size; ++i) {
        stream >> Array[i];
    }
}

bool TMagicSquare::IsMagicSquare(int i, int j) {
    if (j == 3 && RowSum[i] != TargetSum) {
        return false;
    }
    if (i == 3 && ColumnSum[j] != TargetSum) {
        return false;
    }
    if (RowSum[i] > TargetSum || ColumnSum[j] > TargetSum) {
        return false;
    }
    return true;
}

bool TMagicSquare::Permutation(int elem) {
    if (elem == 0) {
        return true;
    }
    int s = Size - elem;
    int column = s % 4;
    int row = s / 4;
    for (int i = 0; i < elem; ++i) {
        int num = Array[i];
        std::swap(Array[i], Array[elem - 1]);
        RowSum[row] += num;
        ColumnSum[column] += num;
        if (IsMagicSquare(row, column)) {
            if (Permutation(elem - 1)) {
                return true;
            }
        }
        RowSum[row] -= num;
        ColumnSum[column] -= num;
        std::swap(Array[i], Array[elem - 1]);
    }
    return false;
}

void TMagicSquare::Solve() {
    for (int i = 0; i < Size; ++i) {
        TargetSum += Array[i];
    }
    if (TargetSum % 4 != 0) {
        std::cout << "NO SOLUTION" << std::endl;
        return;
    }
    TargetSum /= 4;
    if (Permutation(Size)) {
        for (int i = Size - 1; i >= 0; i--) {
            std::cout << Array[i] << ' ';
            if (i % 4 == 0) {
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "NO SOLUTION" << std::endl;
    }
}

int main() {
    TMagicSquare square(16);
    square.ReadArray(std::cin);
    square.Solve();
    return 0;
}
