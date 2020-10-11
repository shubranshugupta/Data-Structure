#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    Node *head;

    Node* traverse(Node *head_ptr, char op){
        if(op == 's'){
            while(head_ptr->next != NULL){
                head_ptr = head_ptr->next;
            }
            return head_ptr;
        }
        if(op == 'd'){
            while(head_ptr != NULL){
                cout<<head_ptr->data<<" ";
                head_ptr = head_ptr->next;
            }
            return NULL;
        }
    }

public:
    LinkedList(){
        head = NULL;
    }

    void add_node(int val){
        Node *new_node = new Node();
        new_node->data = val;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
        }else{
            Node *temp = traverse(head, 's');
            temp->next = new_node;
        }
    }

    void display(){
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
        }else{
            traverse(head, 'd');
        }
    }

    void reverse_lst(){
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
        }else{
            Node *temp_head = head;
            Node* nextnode = NULL;
            Node* revnode = NULL;

            while(temp_head != NULL){
                head = temp_head;
                nextnode = temp_head->next;
                temp_head->next = revnode;
                revnode = temp_head;
                temp_head = nextnode;
            }
        }
    }

    void delete_node(int var, char by){
        if(by == 'p'){
            for(int i=0; i<var; i++){

            }
        }
    }
};

int main()
{
    LinkedList* list1 = new LinkedList();
    list1->add_node(8);
    list1->add_node(4);
    list1->add_node(2);
    list1->display();
    cout<<endl;
    list1->reverse_lst();
    list1->display();
    return 0;
}
