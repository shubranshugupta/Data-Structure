#include <iostream>

using namespace std;

class Node{
    int data;

    public:
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    Node *front, *rear;
    
    public:
        Queue(){
            front = rear = NULL;
        }

        void push(int data){
            if(rear == NULL){
                front = rear = new Node(data);
                return;
            }
            
        }

};