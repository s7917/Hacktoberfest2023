// C++ program to calculate average of array elements
#include <iostream>

int main() {
    int n;

    // Ask the user for the array size
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid array size." << std::endl;
        return 1; // Exit with an error code
    }

    int arr[n];
    double sum = 0.0;

    // Input array elements
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i]; // Calculate the sum as you input elements
    }

    double average = sum / n; // Calculate the average

    std::cout << "Average: " << average << std::endl;

    return 0;
}
