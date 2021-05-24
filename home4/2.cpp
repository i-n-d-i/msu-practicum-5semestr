#include <iostream>
#include <vector>

void Heapify(std::vector<int> &array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(array[i], array[largest]);
        Heapify(array, n, largest);
    }
}

void HeapSort(std::vector<int> &array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }
}

void PrintArray(std::vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n, elem;
    std::cin >> n;
    std::vector<int> array;
    for (int i = 0; i < n; i++) {
        std::cin >> elem;
        array.push_back(elem);
    }
    HeapSort(array, n);
    PrintArray(array, n);
    return 0;
}
