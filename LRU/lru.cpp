#include<bits/stdc++.h>

using namespace std;

class Node{
    int key, value;
    
public:
    Node *prev, *next;
    
    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
    
    int getValue(){
        return this->value;
    }

    int getKey(){
        return this->key;
    }
};

class DoublyLinkList{
    Node *head, *tail;

public:
    DoublyLinkList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    Node* insertNode(int key, int value){
        Node *newNode = new Node(key, value);
        Node *nextHeadNext = head->next;
        
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextHeadNext;
        nextHeadNext->prev = newNode;
        return newNode;
    }
    
    int deleteNode(){
        Node *temp = tail->prev;
        int deleteKey = temp->getKey();
        Node *prevDeletedNode = temp->prev;
        
        prevDeletedNode->next = tail;
        tail->prev = prevDeletedNode;
        delete temp;

        return deleteKey;
    }
    
    void deleteNode(Node *deleteNode){
        Node *prevDeletedNode = deleteNode->prev;
        Node *nextDeletedNode = deleteNode->next;
        
        prevDeletedNode->next = nextDeletedNode;
        nextDeletedNode->prev = prevDeletedNode;
        delete deleteNode;
    }
};

class LRUCache{
    int capacity, count=0;
    DoublyLinkList *dll = new DoublyLinkList();
    unordered_map<int, Node*> hashMap;

public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key){
        if(hashMap.find(key) == hashMap.end()){
            return -1;
        }
        
        int currValue = hashMap[key]->getValue();
        dll->deleteNode(hashMap[key]);
        Node *newNode = dll->insertNode(key, currValue);
        hashMap[key] = newNode;
        
        return currValue;
    }

    void put(int key, int value){
        if(count == capacity && hashMap.find(key) == hashMap.end()){
            int deleteKey = dll->deleteNode();
            hashMap.erase(deleteKey);
            count--;
        }else if(hashMap.find(key) != hashMap.end()){
            dll->deleteNode(hashMap[key]);
            count--;
        }
        
        Node *newNode = dll->insertNode(key, value);
        hashMap[key] = newNode;
        count++;
    }
};

int main(){
    int capacity, totalOper, oper, key, value;
    cout<<"Enter capacity and total operation to perform: ";
    cin>>capacity>>totalOper;
    LRUCache *lru = new LRUCache(capacity);

    for(int i=0; i<totalOper; i++){
        cout<<"Enter type of operation: ";
        cin>>oper;
        if(oper == 1){
            cout<<"Enter key, value: ";
            cin>>key>>value;
            lru->put(key, value);
        }else{
            cout<<"Enter key: ";
            cin>>key;
            cout<<lru->get(key)<<endl;
        }
    }
    return 0;
}
