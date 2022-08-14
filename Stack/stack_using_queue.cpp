#include <iostream>
#include <queue>

using namespace std;

class Stack{
    queue<int> q;

public:
    void push(int data){
        int s = q.size();
        q.push(data);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout<<"Stack is Underflow."<<endl;
        }
        q.pop();
    }

    int top(){
        if(q.empty()){
            return -1;
        }
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }
};

int main(){
    Stack *s1 = new Stack();

    cout<<"S1 is Empty: "<<s1->isEmpty()<<endl;
    s1->push(1);
    s1->push(2);
    s1->push(3);

    cout<<"Top: "<<s1->top()<<endl;
    cout<<"S1 is Empty: "<<s1->isEmpty()<<endl;

    s1->pop();
    s1->pop();
    cout<<"Top: "<<s1->top()<<endl;
    s1->pop();
    s1->pop();

    return 0;
}