#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
private:
    int front, rear, size;
    int que[MAX];

public:
    Queue(){
        front=0;
        rear=-1;
        size=0;
    }

    // Add an element to the end of the queue
    void enqueue(int val) {
    // Check overflow
    if(rear>=MAX-1 && size>=MAX){
        cout<<"Queue is overflow."<<endl;
    }else{
    // Insert element at rear
    // increase rear and size 
    // CODE HERE
    rear++;
    size++;
    que[rear]=val;
    }
    }

    // Remove an element from the front of the queue
    void dequeue() {
        // Check Underflow
        if(size<=0 && rear <=-1){
            cout<<"Queue is underflow."<<endl;
        }
       else{
        // Shift all elements to the left
        for(int i=0;i<size;i++){
            que[i]=que[i+1];
        }
        // Decrease size and rear also
        size--;
        rear--;
       }

    }

    // Get the front element of the queue
    int getFront() {
        // Check Whether queue is empty or not
        if(size==0 && rear==-1){
            return -1;
        }else{
        // If not get front element
        // CODE HERE
        return que[front];
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
    // Chcek whether queue is empty
        if(size==0 && rear==-1){
            return true;
        } return false;
    // CODE HERE
    }

};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << " is at the front of the queue" << endl;

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << q.getFront() << " is at the front of the queue" << endl;
    }

    return 0;
}
