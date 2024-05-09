#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SelecionproblemByBFPRT.cc"
#include "SelectionProblembySorting.cc"

using namespace std;

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

void measureRuntime(int arr[], int n, int k) {
    clock_t start, end;
    double duration;

    // Measure runtime for selectionSort method
    start = clock();
    findKthSmallest(arr, n, k);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Selection Sort: n=" << n << ", k=" << k << " - Runtime: " << duration << " seconds" << endl;

    // Measure runtime for select method
    start = clock();
    select(arr, 0, n - 1, k - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Select Algorithm: n=" << n << ", k=" << k << " - Runtime: " << duration << " seconds" << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int n_values[] = {100, 1000, 10000, 100000, 1000000};
    int k_max = 1000000;

    for (int n : n_values) {
        int arr[n];
        generateRandomArray(arr, n);

        for (int k = 1; k <= n; k++) {
            measureRuntime(arr, n, k);
        }
    }

    return 0;
}