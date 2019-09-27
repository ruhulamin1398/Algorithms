#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node*next;
};



void insertInList(node * head, int data) {

    while ( head->next != NULL) {
        head=  head->next;
    }

    node *newnode ;
    newnode = (node *) malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data= data;
    head->next= newnode;


}



void deleteNode(node *head,int data) {

    while ( head->next != NULL) {
        if(head->next->data==data) {
            head->next= head->next->next;
        } else
            head = head->next;
    }
}



void    deleteFromFirst(node *head) {
    if( head->next != NULL) {
        head->next= head->next->next;
    }
}



void printList(node * head) {

    while ( head->next != NULL) {
        head=  head->next;
        cout<<head->data<<" ";
    }
}


int main() {

    node *head;

    head= (node *) malloc(sizeof(node));
    head->next= NULL;

    insertInList(head, 5);
    insertInList(head, 115);
    insertInList(head, 511);
    insertInList(head, 555);
    insertInList(head, 225);
    insertInList(head, 4545);

    printList(head);
    cout<<endl;

    deleteNode(head,555);
    printList(head);
    cout<<endl;

    deleteFromFirst(head);
    printList(head);
    cout<<endl;




    return 0 ;
}
