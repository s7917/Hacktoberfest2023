#include <algorithm>  /// for algorithm functions
#include <cassert>    /// for assert
#include <iostream>   /// for IO operations
#include <vector>     /// for working with vectors

/**
 * \namespace sorting
 * @brief Sorting algorithms
 */
namespace sorting {

/**
 * \brief Binary search function to find the most suitable pace for an element.
 * \tparam T The generic data type.
 * \param arr The actual vector in which we are searching a suitable place for
 * the element. \param val The value for which suitable place is to be found.
 * \param low The lower bound of the range we are searching in.
 * \param high The upper bound of the range we are searching in.
 * \returns the index of most suitable position of val.
 */
template <class T>
int64_t binary_search(std::vector<T> &arr, T val, int64_t low, int64_t high) {
    if (high <= low) {
        return (val > arr[low]) ? (low + 1) : low;
    }
    int64_t mid = low + (high - low) / 2;
    if (arr[mid] > val) {
        return binary_search(arr, val, low, mid - 1);
    } else if (arr[mid] < val) {
        return binary_search(arr, val, mid + 1, high);
    } else {
        return mid + 1;
    }
}

/**
 * \brief Insertion sort function to sort the vector.
 * \tparam T The generic data type.
 * \param arr The actual vector to sort.
 * \returns Void.
 */
template <typename T>
void insertionSort_binsrch(std::vector<T> &arr) {
    int64_t n = arr.size();

    for (int64_t i = 1; i < n; i++) {
        T key = arr[i];
        int64_t j = i - 1;
        int64_t loc = sorting::binary_search(arr, key, 0, j);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
}  // namespace sorting

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    /* descriptions of the following test */
    /* 1st test:
       [5, -3, -1, -2, 7] returns [-3, -2, -1, 5, 7] */
    std::vector<int64_t> arr1({5, -3, -1, -2, 7});
    std::cout << "1st test... ";
    sorting::insertionSort_binsrch(arr1);
    assert(std::is_sorted(std::begin(arr1), std::end(arr1)));
    std::cout << "passed" << std::endl;

    /* 2nd test:
       [12, 26, 15, 91, 32, 54, 41] returns [12, 15, 26, 32, 41, 54, 91] */
    std::vector<int64_t> arr2({12, 26, 15, 91, 32, 54, 41});
    std::cout << "2nd test... ";
    sorting::insertionSort_binsrch(arr2);
    assert(std::is_sorted(std::begin(arr2), std::end(arr2)));
    std::cout << "passed" << std::endl;

    /* 3rd test:
       [7.1, -2.5, -4.0, -2.1, 5.7] returns [-4.0, -2.5, -2.1, 5.7, 7.1] */
    std::vector<float> arr3({7.1, -2.5, -4.0, -2.1, 5.7});
    std::cout << "3rd test... ";
    sorting::insertionSort_binsrch(arr3);
    assert(std::is_sorted(std::begin(arr3), std::end(arr3)));
    std::cout << "passed" << std::endl;

    /* 4th test:
       [12.8, -3.7, -20.7, -7.1, 2.2] returns [-20.7, -7.1, -3.7, 2.2, 12.8] */
    std::vector<float> arr4({12.8, -3.7, -20.7, -7.1, 2.2});
    std::cout << "4th test... ";
    sorting::insertionSort_binsrch(arr4);
    assert(std::is_sorted(std::begin(arr4), std::end(arr4)));
    std::cout << "passed" << std::endl;
}
