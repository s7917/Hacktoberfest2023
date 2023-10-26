#include <iostream>
#include <algorithm>

using namespace std;

// Function to remove duplicates from an array
void removeDuplicates(int arr[], int& size) {
    sort(arr, arr + size);  // Sort the array first
    size = unique(arr, arr + size) - arr;  // Remove duplicates and update the size
}

int main() {
    int array[] = {3, 1, 2, 2, 3, 4, 5, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    removeDuplicates(array, size);

    cout << "\nArray after removing duplicates: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}
