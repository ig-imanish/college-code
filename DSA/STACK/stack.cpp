#include <iostream>
#define MAX 5
using namespace std;
class Stack {
private:
    int stk[MAX];  
    int top;      

public:
    Stack() {top =-1;}  

    void push(int val){
        if(top>=MAX-1){
            cout<<"Stack overflow"<<endl;
        }else{
            stk[++top]=val;
        }

    }

    void pop() {
        if(top<=-1){
            cout<<"stack undreflow"<<endl;
        }else{
            top--;
        }

    }

    int peek() {
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return top;
    }else{
        return stk[top];
    }
    }

    bool empty() {
        if(top==-1){
            return true;
        }
        return false;

    }


    int size() {
        return top++;
 
    }
};

int main() {
    Stack S;


    S.push(302);
    S.push(300);
    S.push(33);


    cout << "Top element: " << S.peek() << endl;


    S.pop();
    cout << "Top element after pop: " << S.peek() <<endl;

    S.push(40);
    cout << "Top element after another push: " << S.peek() << endl;

    S.push(500);
    S.push(640);  
    S.push(720);  

    cout << "Size of the stack: " << S.size() << std::endl;


    while (!S.empty()) {
        S.pop();
    }


    S.pop();

    return 0;
}
