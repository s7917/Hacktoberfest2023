#include <iostream>
using namespace std;

void merge(int *arr, int l, int mid, int r) {

    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];

    for(int i = 0; i < mid-l+1; i++) a[i] = arr[l+i];
    for(int i = 0; i < r-mid; i++) b[i] = arr[mid+1+i];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++; i++;
        }
        else {
            arr[k] = b[j];
            k++; j++;
        }
    }

    while(i < n1) {
        arr[k] = a[i];
        k++; i++;
    }

    while(j < n2) {
        arr[k] = b[j];
        k++; j++;
    }
}

void MergeSort(int *arr, int l, int r) {
    if (l < r)
    {
        int mid = (l+r)/2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
    
}


int main(void) {
    int arr[] = {6,3,9,4,5,2,8,7,1};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,l,r-1);

    for(int i = 0; i < r; i++) {
        cout << arr[i] << " ";
    }
}