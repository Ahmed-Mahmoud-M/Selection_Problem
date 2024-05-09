#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int findKthSmallest(int arr[], int n, int k) {
    selectionSort(arr, n);
    return arr[k - 1];
}

// int main() {
//     int arr[] = {12, 3, 5, 7, 4, 19, 26};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 1;

//    cout << "The " << k << "-th smallest element is "
// 		 << findKthSmallest(arr, n, k) << endl;

//     return 0;
// }
