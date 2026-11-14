#include <iostream>
using namespace std;

int partitionArray(int prices[], int low, int high) {
    int pivot = prices[high];
    int i = low - 1;

for (int j = low; j < high; j++) {
        if (prices[j] < pivot) {
            i++;
            swap(prices[i], prices[j]);
        }
    }

swap(prices[i + 1], prices[high]);
    return i + 1;
}

void quickSort(int prices[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(prices, low, high);

quickSort(prices, low, pivotIndex - 1);
        quickSort(prices, pivotIndex + 1, high);
    }
}

int main() {
    int n;

cout << "Enter number of products: ";
    cin >> n;

int* prices = new int[n];

for (int i = 0; i < n; i++) {
        cout << "Enter price " << i + 1 << ": ";
        cin >> prices[i];
    }

quickSort(prices, 0, n - 1);

cout << "Prices in ascending order:\n";

for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }

delete[] prices;
    return 0;
}
