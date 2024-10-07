#include <iostream>
using namespace std;
void selectionSort(int arr[], int n){
  for(int i=0; i < n; i++){
    int min = i;
    for(int j = i+1; j < n; j++){
      if(arr[j] < arr[min]){
        min = j;
        break;
      }
    }
    if(min != i){
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}
void print(int arr[], int n){
  for(int i=0; i <n ; i++){
    cout << arr[i] << " ";
  }
}
int main() 
{
  
  int arr[] = { 23,3,54,6,7,8,9,94};
  int n = 8;
  
  selectionSort(arr, n);
  print(arr, n);
    return 0;
}
