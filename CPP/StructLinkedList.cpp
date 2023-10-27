#include<iostream>
using namespace std;

struct LinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    Node *head;
    int size = 0;
    LinkedList(int x=-999) {
        Node *newnode =  new Node(x);
        head = newnode;        
        size+=1;
    }
    bool isEmpty() {
        return (head == NULL ? true : false);
    }
    int findElement(int x) {
        Node *curr = head;
        int pos = 0;
        bool flag=false;
        while(curr!=NULL){
            pos+=1;
            if(curr->data == x) {
                flag=true;
                break;
            }
            curr = curr->next;
        }
        if(flag){
        return pos;
        }
        return 0;
    }
    void insertH(int x) {
        Node *newnode = new Node(x);
        if(isEmpty())
            head = newnode;
        else{
        newnode->next = head;
        head = newnode;
        }
        size+=1;
    }
    void insertT(int x) {
        Node *newnode = new Node(x);
        if(isEmpty()) {
            head = newnode;
        }
        else {
            Node *curr = head;
            while(curr->next!=NULL) {
                curr = curr->next;
            }
            curr->next = newnode;
        }
        size+=1;
    }
    void insertP(int p, int x) {
        if(isEmpty()) {
            cout << "Empty List. Inserting << " << x << " on head" << endl;
            insertH(x);
        }
        else if(p < 1 || p > size + 1) {
            cout << "Invalid Operation.\nPosition " << p << " is not valid, could not insert " << x << endl;
            return ;
        }
        else if(p == 1) {
            insertH(x);
        }
        else if(p == size+1) {
            insertT(x);
        }
        else {
            Node *newnode = new Node(x);
            Node *curr = head;
            int c=1;
            while(c != p-1) {
                curr = curr->next;
                c++;
            }
            newnode->next = curr->next;
            curr->next = newnode;
        }
        size+=1;
    }
    void deleteH() {
        if(isEmpty()){
            cout << "Invalid Operation.\nList is EMPTY" << endl;
            return ;
        }
        else {
            Node *c = head;
            head = c->next;
            free(c);
            size-=1;
        }
    }
    void deleteT(){
         if(isEmpty()){
            cout << "Invalid Operation.\nList is EMPTY" << endl;
            return ;
        }
        else {
            Node *curr = head;
            while(curr->next->next != NULL) {
                curr = curr->next;
            }
            free(curr->next);
            curr->next = NULL;
            size-=1;
        } 
    }
    void deleteP(int p) {
        if(isEmpty()) {
            cout << "Invalid Operation.\nList is EMPTY" << endl;
            return ;
        }
        else if(p < 1 || p > size) {
            cout << "Invalid Operation.\nPosition " << p << " is not valid, could not delete" << endl;
            return ;
        }
        else if(p == 1) {
            deleteH();
        }
        else if(p == size) {
            deleteT();
        }
        else {
            Node *curr = head;
            int c=1;
            while(c != p-1) {
                curr = curr->next;
                c+=1;
            }
            Node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        size-=1;
    }
    void deleteEl(int x){
        int p = findElement(x);
        if(p == 0) {
            cout << "Invalid Operation.\nElement " << x << " not found in the list" << endl;
            return ;
        }
        else {
            deleteP(p);
        }
    }
    void traverse() {
        Node *curr = head;
        while(curr!=NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() 
{
    LinkedList *l = new LinkedList(2);
    l->insertT(3);
    l->insertH(4);
    l->insertT(9);
    l->insertH(6);
    l->insertT(7);
    l->traverse();
    l->deleteP(2);
    l->traverse();
    return 0;
}
