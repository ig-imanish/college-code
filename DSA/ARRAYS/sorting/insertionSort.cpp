#include <iostream>
using namespace std;
void insertionSort(int arr[], int n){
  for(int i=1; i < n; i++){
    int j = i-1;
    int key =arr[i];
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
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
  
  insertionSort(arr, n);
  print(arr, n);
    return 0;
}
