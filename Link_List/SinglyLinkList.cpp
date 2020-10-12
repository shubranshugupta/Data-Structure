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
        if(op == 'p'){
            while(head_ptr != NULL){
                cout<<head_ptr->data<<" ";
                head_ptr = head_ptr->next;
            }
            return NULL;
        }
    }

public:
    int len=0;
    LinkedList(){
        head = NULL;
    }

    void add_node(int val){
        len++;
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
            traverse(head, 'p');
        }
    }


    void reverse_lst(){
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
            return;
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
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
            return;
        }
        if(by == 'p'){
            Node *prevnode = NULL, *tempnode = head;
            if(var == 0){
                if(head->next == NULL){
                    delete head;
                    head = NULL;
                    len--;
                    return;
                }else{
                    head = tempnode->next;
                    delete tempnode;
                    len--;
                    return;
                }
            }
            if(var > 0 && var < len){
                int i = 0;
                while(i<var){
                    prevnode = tempnode;
                    tempnode = tempnode->next;
                    i++;
                }
                prevnode->next = tempnode->next;
                delete tempnode;
                len--;
                return;
            }else{
                cout<<"Out of range"<<endl;
            }
        }
        if(by == 'd'){
            Node *temp = head;
            for(int i = 0; i<len; i++){
                if(temp->data == val){
                    
        }
    }
};

int main()
{
    LinkedList* list1 = new LinkedList();
    list1->add_node(8);
    list1->add_node(4);
    //list1->add_node(2);
    list1->display();
    cout<<endl;
    cout<<list1->len<<endl;
    //list1->reverse_lst();
    //list1->display();
    //cout<<endl;
    list1->delete_node(0, 'p');
    list1->display();
    cout<<endl;
    list1->add_node(2);
    cout<<endl;
    list1->display();
    cout<<endl;
    cout<<list1->len<<endl;
    return 0;
}
