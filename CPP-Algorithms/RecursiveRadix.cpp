#include <iostream>
#include <vector>

int getMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void recursiveCountingSort(std::vector<int>& arr, int exp, int n) {
    if (n <= 1) {
        return;
    }

    const int k = 10; 
    std::vector<int> output(n);
    std::vector<int> count(k, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % k]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % k] - 1] = arr[i];
        count[(arr[i] / exp) % k]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void recursiveRadixSort(std::vector<int>& arr, int exp) {
    int n = arr.size();

    if (exp <= 0) {
        return;
    }

    recursiveCountingSort(arr, exp, n);

    recursiveRadixSort(arr, exp / 10);
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    printArray(arr);

    int max = getMax(arr);
    recursiveRadixSort(arr, max);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
