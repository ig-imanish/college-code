#include<iostream>
using namespace std;
int main(){
    int n;
    int pos;

    cout<<"Enter the size of array:";
    cin>>n;

    cout<<"Enter the elements in array:";
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the position where you inserted the number:";
    cin>>pos;


    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
       cout<<arr[i]<<endl;
    }
    n--;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
