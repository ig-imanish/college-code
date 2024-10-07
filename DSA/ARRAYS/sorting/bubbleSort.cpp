#include <iostream>
using namespace std;
void BubbleSort(int arr[], int n){
  for(int i=0; i < n; i++){
    for(int j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
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
  
  BubbleSort(arr, n);
  print(arr, n);
    return 0;
}
