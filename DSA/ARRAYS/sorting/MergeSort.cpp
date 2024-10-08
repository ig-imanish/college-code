#include <iostream>
using namespace std;
void mergeArray(int arr[], int beg, int mid, int end){
    int n1 = mid - beg + 1; 
    int n2 = end - mid; 
    int arr1[n1], arr2[n2];  
    for(int i = 0; i < n1; i++){
        arr1[i] = arr[beg + i];
    }
    for(int i = 0; i < n2; i++){
        arr2[i] = arr[mid + 1 + i];
    }    
    int i = 0, j = 0, k = beg; 
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    } 
    // Copy remaining elements of arr1[], if any
    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    } 
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int beg, int end){
    if(beg < end){
        int mid = beg + (end - beg) / 2;    
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        mergeArray(arr, beg, mid, end);
    }
}
void printArr(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {45, 3, 5, 8, 5, 5, 8, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    printArr(arr, n); 
    return 0;
}
