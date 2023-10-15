#include <iostream>
using namespace std;
/* if the total numbers are 12,3,2,4,1
then the special sum will be calculated from first index like
a[0]=a[0]+(a[1]+a[2])+(a[3]+a[4]+a[5])+(a[6]+a[7]+a[8]+a[9])...
a[1]=a[1]+(a[2]+a[3])+(a[4]+a[5]+a[6])+(a[7]+a[8]+a[9]+a[10])...
if there is any index which does not exist then that part of sum will not be calculated for example if a[5] does not exit then this part (a[4]+a[5]+a[6])+(a[7]+a[8]+a[9]+a[10])... will not be calculated*/
int calculateSpecialSum(int arr[], int n, int index) {
    int specialSum = arr[index];
    for (int i = index + 2; i < n; i += 2) {
        specialSum += arr[i];
    }
    return specialSum;
}

int main() {
    int n, arr[20];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int bestIndex = -1;  // Initialize to an invalid index
    int maxSpecialSum = 0;

    for (int i = 0; i < n; i++) {
        int specialSum = calculateSpecialSum(arr, n, i);
        if (specialSum > maxSpecialSum) {
            maxSpecialSum = specialSum;
            bestIndex = i;
        }
    }

    if (bestIndex == -1) {
        cout << "No valid index found." << endl;
    } else {
        cout << "The largest special sum is: " << maxSpecialSum+1 << " at index " << bestIndex << endl;
    }

    return 0;
}
