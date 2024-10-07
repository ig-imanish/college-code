#include <iostream>
using namespace std;
void TowerOfHanoi(int n,char source,char destination,char auxiliary){
    if(n==1){
        cout<<"Move disk "<<n<<"from "<<source<<"to "<<destination<<endl;
        return ;
    }
    TowerOfHanoi(n-1,source,auxiliary,destination);
    cout<<"Move disk "<<n<<"from "<<source<<"to "<<destination<<endl;
    TowerOfHanoi(n-1,auxiliary,destination,source);
}
int main(){
    int n=3;
    // cout<<"Enter the number of disks:";
    // cin>>n;
    TowerOfHanoi(n,'A','C','B');
    cout<<endl;
    
    return 0;
}
