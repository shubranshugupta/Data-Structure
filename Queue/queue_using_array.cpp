#include <iostream>

using namespace std;

#define MAXSIZE 10

class Queue {
    int *arr;
    int rear, size;

    public:
        Queue(){
            arr = new int[MAXSIZE];
            rear = -1;
            size = MAXSIZE;
        }

        Queue(int size) {
            this->size = size;
            arr = new int[size];
            rear = -1;
        }

        ~Queue() {
            delete[] arr;
        }

        void push(int data){
            if(rear == size-1){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            rear++;
            arr[rear] = data;
        }

        void pop(){
            if(rear == -1){
                cout<<"Queue Underflow"<<endl;
                return;
            }

            for(int i=0; i<size; i++){
                arr[i] = arr[i+1];
            }
            rear--;
        }

        int peek(){
            if(rear == -1){
                return -1;
            }

            return arr[0];
        }

        bool isEmpty(){
            return rear == -1;
        }

};

int main(){

    Queue *q = new Queue(3);
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);

    cout<<q->peek()<<endl;
    q->pop();
    cout<<q->peek()<<endl;
    q->pop();
    cout<<q->peek()<<endl;
    q->pop();
    cout<<q->peek()<<endl;
    q->pop();

    return 0;
}