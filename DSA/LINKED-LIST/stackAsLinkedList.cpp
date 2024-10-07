#include <iostream>
using namespace std;

struct Node{
  int data;
  Node*next;
  Node(int num){
    data=num;
    next=nullptr;
  }
};
Node* Top=nullptr;


void push(int num){
  Node * ptr=new Node(num);
  if(Top==nullptr){
    Top=ptr;
  }else{
    ptr->next=Top;
    Top=ptr;
  }
}

void pop(){
  if(Top==nullptr){
    cout<<"Underflow ! cannot pop"<<endl;
  }else{
    Node*ptr=Top;
    Top=Top->next;
    delete ptr;
  }
}

void peek(){
  if(Top==nullptr){
    cout<<"Stack is empty "<<endl;
    return;
  }
  cout<<endl<<Top->data<<endl;
}

bool isEmpty(){
  return Top==nullptr;
}
void traverse(){
    if(Top==nullptr){
    cout<<"Stack is empty"<<endl;
  }else{
    Node*ptr=Top;
    while(ptr!=nullptr){
      cout<<ptr->data<<"->";
      ptr=ptr->next;
    }
  }
}
int main() 
{
    traverse();
    push(30);
    push(20);
    push(10);
    traverse();
    peek();
    pop();
    traverse();
    peek();
    pop();
    traverse();
    peek();
    pop();
    traverse();
    cout<<isEmpty();
    return 0;
}
