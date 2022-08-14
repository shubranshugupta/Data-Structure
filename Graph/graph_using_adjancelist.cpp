#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Node{
    T data;

    public:
        Node *next;
        
        Node(T d){
            data = d;
            next = NULL;
        }

        T getData(){
            return data;
        }
};

class Graph{

    int vertex;
    vector<Node<int>*> *adj;

    public:
        Graph(int v){
            vertex = v;
            adj = new vector<Node<int>*>(v, NULL);
        }
        
        void addEdge(int u, int v){
            if(u >= vertex || v >= vertex){
                cout << "Invalid vertex" << endl;
                return;
            }
            
            if(u == v){
                cout << "Self loop not allowed" << endl;
                return;
            }
            
            Node<int> *newNode = new Node<int>(v);
            newNode->next = adj->at(u);
            adj->at(u) = newNode;
            
            newNode = new Node<int>(u);
            newNode->next = adj->at(v);
            adj->at(v) = newNode;
        }
        
        void printGraph(){
            for(int i = 0; i < vertex; i++){
                Node<int> *temp = adj->at(i);
                while(temp != NULL){
                    cout<<temp->getData()<<"->";
                    temp = temp->next;
                }
                cout<<"NULL"<<endl;
            }
        }
        
        ~Graph(){
            for(int i = 0; i < vertex; i++){
                Node<int> *temp = adj->at(i);
                while(temp != NULL){
                    Node<int> *temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                }
            }
            delete adj;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printGraph();
    
    return 0;
}