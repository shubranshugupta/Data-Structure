#include <iostream>
#include<tuple>
#include<algorithm>

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

    tuple <int, int> node_val(Node *head_ptr, int pos1, int pos2=-1){
        int var1, var2;
        if(pos2 != -1){
            for(int i=0; i<=len; i++){
                if(i == pos1){
                    var1 = head_ptr->data;
                }

                if(i == pos2){
                    var2 = head_ptr->data;
                    return make_tuple(var1, var2);
                }
                head_ptr = head_ptr->next;
            }
        }else{
            for(int i=0; i<=len; i++){
                if(i == pos1){
                    var1 = head_ptr->data;
                    return make_tuple(var1, NULL);
                }
                head_ptr = head_ptr->next;
            }
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


    void delete_node(int var, char by='p'){
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
            Node *temp = head, *prevnode = NULL;
            for(int i = 0; i<len; i++){
                if(temp->data == var && prevnode == NULL){
                    head = temp->next;
                    delete temp;
                    len--;
                    break;
                }

                if(temp->data == var){
                    prevnode->next = temp->next;
                    delete temp;
                    len--;
                    break;
                }
                prevnode = temp;
                temp = temp->next;
            }

            if(temp == NULL){
                cout<<"Value Not Present"<<endl;
            }
        }
    }

    int search(int var){
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
            return -2;
        }

        Node *temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == var){
                return pos;
            }
            pos++;
            temp = temp->next;
        }

        if(pos == len){
            return -1;
        }
    }

    void change(int pos, int var, char by='p'){
        if(head == NULL){
            cout<<"Link List is Empty."<<endl;
            return;
        }

        if(by == 'p'){
            if(len<pos+1){
                cout<<"Out of range"<<endl;
                return;
            }
            Node *temp = head;
            for(int i = 0; i<pos; i++){
                temp = temp->next;
            }
            temp->data = var;
        }

        if(by == 'd'){
            pos = search(pos);
            if(pos == -1){
                cout<<"Element not present"<<endl;
                return;
            }
            change(pos, var);
        }
    }

    void swap(int pos1, int pos2){
        if(pos1 > (len-1) || pos2 > (len-1)){
            cout<<"Out of range"<<endl;
            return;
        }

        int var1, var2;
        if(pos1 < pos2){
            tie(var1, var2) = node_val(head, pos1, pos2);
            change(pos1, var2);
            change(pos2, var1);
        }else{
            tie(var2, var1) = node_val(head, pos2, pos1);
            change(pos1, var2);
            change(pos2, var1);
        }
    }

    void sort(){
        
    }
};

int main()
{
    LinkedList* list1 = new LinkedList();
    // list1->add_node(8);
    // list1->add_node(4);
    // list1->add_node(2);
    // list1->display();
    // cout<<endl;
    // list1->swap(2, 0);
    // list1->display();
    // cout<<list1->len<<endl;
    // list1->reverse_lst();
    // list1->display();
    // cout<<endl;
    // list1->change(4, 7, 'd');
    // cout<<endl;
    // list1->display();
    // cout<<endl;
    // list1->add_node(2);
    // cout<<endl;
    // list1->display();
    // cout<<endl;
    // cout<<list1->len<<endl;
    return 0;
}
