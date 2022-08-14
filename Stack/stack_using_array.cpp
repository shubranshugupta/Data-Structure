#include <iostream>
using namespace std;

#define MAXSIZE 50

class Stack {
    int t, n, *arr;
    
public:

    Stack() {
        n = MAXSIZE;
        arr = new int[MAXSIZE];
        t = -1;
    }
    
    Stack(int capacity) {
        n = capacity;
        arr = new int[capacity];
        t = -1;
    }
    
    ~Stack()
    {
        delete[] arr;
    }

    void push(int num) {
        if(t>n){
            return;
        }
        arr[++t] = num;
    }

    int pop() {
        if(t<0){
            return -1;
        }
        return arr[t--];
    }
    
    int top() {
        if(t<0){
            return -1;
        }
        return arr[t];
    }
    
    int isEmpty() {
        if(t == -1){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(t == n-1){
            return 1;
        }
        return 0;
    }
    
};

int main()
{
    Stack *s1;
    s1 = new Stack();
    cout << "S1 is Empty: " << s1->isEmpty() << endl;
    cout << "S1 is Full: " << s1->isFull() << endl;

    for (int i = 0; i < 50; i++)
    {
        s1->push(i);
    }

    cout << "S1 is Full: " << s1->isFull() << endl;

    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    cout << s1->topVal() << endl;
    cout << s1->pop() << endl;
    
    s1->push(100);
    cout << s1->topVal() << endl;

    delete s1;
    return 0;
}