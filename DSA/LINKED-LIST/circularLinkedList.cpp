#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int num) {
        data = num;
        next = nullptr;
    }
};
Node* head = nullptr;

void traverse() {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
    } else {
        Node* ptr = head;
        // while(ptr->next != head){
        //     cout<<ptr->data<<"->";
        //     ptr=ptr->next;
        // } 
        // cout<<ptr->data<<"->";
        // cout<<"head"<<endl; 

        do{
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }while(ptr!=head);
        cout<<"head"<<endl; 
    }
}
// INSERTION----------------------------------------------------
void insertBeg(int num) {
    Node* new_node = new Node(num);
    if (head == nullptr) {
        head = new_node;
        new_node->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}
void insertEnd(int num) {
    Node* new_node = new Node(num);
    if (head == nullptr) {
        head = new_node;
        new_node->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void insertAfterGivenValue(int num,int givenValue){
    Node *new_node=new Node(num);    
    Node*ptr =head;
    if(head->next==head){
        new_node->next=head;
        head=new_node;
    }
    while(ptr->next!=head && ptr->data!=givenValue){
        ptr=ptr->next;
    }

    if(ptr->next == head){
        cout<<"Given value is not found"<<endl;
        return;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
}

void insertBeforeGivenValue(int num,int givenValue){
    Node *new_node=new Node(num);    
    Node*ptr =head;
    Node*p=head->next;
    while(ptr->next!=head && ptr->data!=givenValue){
        ptr=ptr->next;
        p=p->next;
    }

    if(ptr->next == head){
        cout<<"Given value is not found"<<endl;
        return;
    }
    new_node->next=p;
    ptr->next=new_node;
}
// DELETION-------------------------------------------------------------
void deleteBeg() {
    if (head == nullptr) {
       cout<<"Linked List is empty"<<endl;
    }else if(head->next==head){
        delete head;
        head=nullptr;
    }  else {
       Node *ptr=head;
       Node*temp=head;
       while(temp->next!=head){
        temp=temp->next;
       }
       head=head->next;
       temp->next=head;
       delete ptr;
    }
}
void deleteEnd() {
     Node *ptr=head;
     Node* temp =head->next;
    if (head == nullptr) {
        cout<<"Linked List is empty"<<endl;
    }else if(head->next==head){
        delete head;
        head=nullptr;
    } 
    else {
        while (temp->next != head) {
            ptr=ptr->next;
            temp = temp->next;
        }
        ptr->next=head;
        delete temp;
    }
}

void deleteAfterGivenValue(int givenValue){
    Node*ptr =head;
    Node*temp=head->next;
    while(ptr->next!=head && ptr->data!=givenValue){
        temp=temp->next;
        ptr=ptr->next;
    }

    if(ptr->next == head){
        if(ptr->data==givenValue){
        cout<<"There is no elemet after given value "<<givenValue<<endl;
    }else{
        cout<<"Given value is not found"<<endl;
    }
    return;
    }
    
    ptr->next=temp->next;
    delete temp;
}
void deleteBeforeGivenValue(int givenValue) {
    if (head == nullptr || head->next == head) {
        cout << "The list is too short to delete any node." << endl;
        return;
    }

    Node* temp = head;
    Node* ptr = nullptr;

    while (temp->next != head && temp->next->data != givenValue) {
        ptr = temp;
        temp = temp->next;
    }


    if (head->data == givenValue) {
        cout << "There is no element before the given value." << endl;
        return;
    }
    
    if (temp->next->data != givenValue) {
        cout << "Given value not found in the list." << endl;
        return;
    }

    if (temp == head && head->next->data == givenValue) {
        cout << "There is no element before the given value." << endl;
        return;
    }

    ptr->next = temp->next;
    delete temp;
}


int main() {
    insertBeg(10);
    insertBeg(20);
    insertBeg(30);
    traverse();
    insertAfterGivenValue(40,50);
    traverse();
    insertBeforeGivenValue(40,30);
    traverse();
    insertEnd(90);
    traverse();
    deleteBeg();
    traverse();
    deleteEnd();
    traverse();
    deleteAfterGivenValue(10);
    traverse();
    deleteBeforeGivenValue(20);
    traverse();
}
