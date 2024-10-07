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
Node* front=nullptr;
Node* rear=nullptr;

void enque(int num){
  Node * ptr=new Node(num);
  if(front==nullptr && rear==nullptr){
    front=rear=ptr;
  }else{
    rear->next=ptr;
    rear=ptr;
  }
}

void deque(){
  if(front==nullptr && rear==nullptr){
    cout<<"Underflow ! cannot deque"<<endl;
  }else{
    Node*ptr=front;
    front=front->next;
    delete ptr;
  }
}

void fronnt(){
  if(front==nullptr && rear==nullptr){
    cout<<"Stack is empty "<<endl;
    return;
  }
  cout<<endl<<front->data<<endl;
}

bool isEmpty(){
  return front==nullptr;
}
void traverse(){
    if(front==nullptr || rear == nullptr ){
    cout<<"Queue is empty"<<endl;
  }else{
    Node*ptr=front;
    while(ptr!=nullptr){
      cout<<ptr->data<<"->";
      ptr=ptr->next;
    }

  }
}
int main() 
{
    traverse();
    enque(30);
    enque(20);
    enque(10);
    traverse();
    fronnt();
    deque();
    traverse();
    fronnt();
    deque();
    traverse();
    fronnt();
    deque();
    traverse();
    cout<< isEmpty();
    return 0;
}
