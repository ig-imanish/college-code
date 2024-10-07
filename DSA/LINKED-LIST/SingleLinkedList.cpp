#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int num){
    data=num;
    next=nullptr;
  }
};
Node *head=nullptr;

void traverse(){
  if(head==nullptr){
    cout<<"Linked List is empty."<<endl;
    return;
  }
  Node *ptr=head;
  while(ptr!=nullptr){
    cout<<ptr->data<<" ";
    ptr=ptr->next;
  }
  cout<<endl;
}

void insertAtBeg(int num){
  Node *p= new Node(num);
  if(head==nullptr){
    head=p;
    return;
  }
  else{
    p->next=head;
    head=p;
  }
}

void insertAfterGivenNode(int num, int givenValue) {
    Node *p = new Node(num);
    Node *ptr = head;

    // Traverse the list to find the given value
    while (ptr != nullptr && ptr->data != givenValue) {
        ptr = ptr->next;
    }

    // If ptr is nullptr, the node with the given value was not found
    if (ptr == nullptr) {
        cout << "Given Node is not found in linked list" << endl;
        return;
    }

    // Insert after the found node
    p->next = ptr->next;
    ptr->next = p;
}


void insertBeforeGivenNode(int num, int givenValue) {
    Node *p = new Node(num);

    // Special case: if the given value is in the head node
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == givenValue) {
        p->next = head;
        head = p;
        return;
    }

    Node *ptr = head;
    Node *q = ptr->next;

    // Traverse the list to find the node before the given node
    while (q != nullptr && q->data != givenValue) {
        ptr = ptr->next;
        q = q->next;
    }

    // If q is nullptr, the node with the given value was not found
    if (q == nullptr) {
        cout << "Given Node is not found in linked list" << endl;
        return;
    }

    // Insert before the found node
    p->next = ptr->next;
    ptr->next = p;
}

void insertAtEnd(int num){
  Node *p= new Node(num);
  Node *ptr=head;

  if(ptr==nullptr){
    p->next=ptr;
    ptr=p;
    return;
  }
 
  while(ptr->next!=nullptr){
    ptr=ptr->next;
    
  }
  ptr->next=p;
  p->next=nullptr;
}


void deletionAtBeg(){
  if(head==nullptr){
    cout<<"Linked list is empty ";
  }else{
    Node *ptr=head;
    head=head->next;
    delete ptr;
    return ;
    }
}

void deletionAtEnd(){
    if(head==nullptr){
    cout<<"Linked list is empty ";
  }else{
    Node *ptr=head;
    Node *postPtr=head->next;
    while(postPtr->next!=nullptr){
      ptr=ptr->next;
      postPtr=postPtr->next;
    }
    ptr->next=nullptr;
    delete postPtr;
    return ;
  }
}

void deletionAfterGivenValue(int val){
      if(head==nullptr){
    cout<<"Linked list is empty ";
  }else{
    Node *ptr=head;
    Node *postPtr=head->next;
    while(ptr->next!=nullptr && ptr->data!=val){
      ptr=ptr->next;
      postPtr=postPtr->next;
    }
    ptr->next=postPtr->next;
    delete postPtr;
    return ;
  }
}


void deletionBeforeGivenValue(int val) {
    if (head == nullptr) {
        cout << "Linked list is empty\n";
        return;
    }

    // Special case: If there's only one node or the head itself is the target value
    if (head->data == val || head->next == nullptr ) {
        cout << "No node exists before the given value\n";
        return;
    }
    if(head->next->data==val){
      head=head->next;
      return;
    }

    Node *prePtr = nullptr;
    Node *ptr = head;
    Node *postPtr = head->next;

    while (postPtr->next != nullptr && postPtr->data != val) {
        prePtr = ptr;
        ptr = ptr->next;
        postPtr = postPtr->next;
    }

    // If value is not found
    if (postPtr->data != val) {
        cout << "Value not found in the list\n";
        return;
    }

    // If we have valid pointers, delete the node before the value
    if (prePtr != nullptr) {
        prePtr->next = postPtr;
        delete ptr;
    }
}


int main() 
{
  // INSERTION 
  insertAtBeg(10);
  traverse();
  insertAtBeg(40);
  traverse();
  insertBeforeGivenNode(30,10);
  traverse();
  insertAfterGivenNode(20,30);
  traverse();
  insertAtEnd(0);
  traverse();
    //deletion
  deletionAtBeg();
  traverse();
  deletionAtEnd();
  traverse();
  deletionAfterGivenValue(20);
  traverse();
  deletionBeforeGivenValue(20);
  traverse();
  return 0;
}
