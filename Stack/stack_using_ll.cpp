#include<iostream>
using namespace std;

class Node{
    int data;

public:
    Node *next;
    Node *prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    int getData(){
        return this->data;
    }
};

class Stack{
    Node *top;

public:
    Stack(){
        this->top = NULL;
    }

    bool isEmpty(){
        if(this->top == NULL){
            return true;
        }
        return false;
    }

    int topVal(){
        if(this->top == NULL){
            return -1;
        }
        return this->top->getData();
    }

    void push(int data){
        Node *newNode = new Node(data);
        if(this->top == NULL){
            this->top = newNode;
        }
        else{
            newNode->prev = this->top;
            this->top->next = newNode;
            this->top = newNode;
        }
    }

    void pop(){
        if(this->top == NULL){
            cout<<"Stack is Underflow."<<endl;
        }

        Node *temp = this->top;
        this->top = this->top->prev;
        if(this->top != NULL){
            this->top->next = NULL;
        }
        delete temp;
    }
};

int main(){
    Stack *s1 = new Stack();
    cout<<"S1 is Empty: "<<s1->isEmpty()<<endl;

    s1->push(1);
    s1->push(2);
    s1->push(3);
    s1->push(4);
    cout<<"S1 is Empty: "<<s1->isEmpty()<<endl;
    cout<<"S1 topVal: "<<s1->topVal()<<endl;

    s1->pop();
    cout<<"S1 topVal: "<<s1->topVal()<<endl;
    s1->pop();
    s1->pop();
    s1->pop();
    s1->pop();

    return 0;
}