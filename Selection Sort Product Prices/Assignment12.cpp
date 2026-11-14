#include <iostream>
using namespace std;

void selectionSort(int prices[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minimumIndex = i;

for (int j = i + 1; j < n; j++) {
            if (prices[j] < prices[minimumIndex]) {
                minimumIndex = j;
            }
        }

swap(prices[i], prices[minimumIndex]);
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

selectionSort(prices, n);

cout << "Prices in ascending order:\n";

for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }

delete[] prices;
    return 0;
}
